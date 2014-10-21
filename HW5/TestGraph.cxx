//Name: Edward Zhu
//Lecture - MWF 10AM

#include <fstream>
#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include "GraphTemplate.h"
using namespace std;
using namespace elizabeth_white_stl_vector_adjacency_matrix;

// **************************************************************************
double greatCircleDistance(const Vertex& v, const Vertex& u);
bool doesDFSPathExist(const Graph& g, const vector<string>& cities, const string& city1, const string& city2);
bool doesBFSPathExist(const Graph& g, const vector<string>& cities, const string& city1, const string& city2);
bool depthFirstSearch(const Graph& g, const vector<string>& cities, const string& u, map<string, bool>& visited, vector<string>& yetToExplore, map<string, string>& predecessors);
bool breadthFirstSearch(const Graph& g, const vector<string>& cities, const string& u, map<string, bool>& visited, vector<string>& yetToExplore, map<string, string>& predecessors);
void initGraphFromFile(Graph& g, vector<string>& cities, const string& fileName, double limit);
void openForRead(ifstream& f, const char filename[]);
bool isMoreStuffThere(ifstream& f);
   


double greatCircleDistance(const Vertex& v, const Vertex& u)
{
	double PI = 3.1415926535897932;
	double lat1, lat2, long1, long2, dist;

	lat1 = ((double) v.getLatDegrees()) + (((double) v.getLatMinutes()) / 60.0);
	lat1 *= PI/180.0;
	long1 = ((double) v.getLongDegrees()) + (((double) v.getLongMinutes()) / 60.0);
	long1 *= PI/180.0;
	lat2 = ((double) u.getLatDegrees()) + (((double) u.getLatMinutes()) / 60.0);
	lat2 *= PI/180.0;
	long2 = ((double) u.getLongDegrees()) + (((double) u.getLongMinutes()) / 60.0);
	long2 *= PI/180.0;

	// from http://www.meridianworlddata.com/Distance-Calculation.asp
	// result in km
	dist = 6378.7 * acos((sin(lat1) * sin(lat2)) + (cos(lat1) * cos(lat2) * cos(long2 - long1)));

	return dist;
}

// check whether a path exists via depth first search.
bool doesDFSPathExist(const Graph& g, const vector<string>& cities, const string& city1, const string& city2)
{
	vector<string> yetToExplore;
	map<string, bool> visited;
	map<string, string> predecessors;

	// check for the special case that we are already there
	if (city1.compare(city2) == 0)
	{
		cout << "Same city!" << endl;
		return true;
	}

	// initialize both the visited map and the neighbors map
	vector<string>::const_iterator it;
	
	for (it = cities.begin(); it != cities.end(); ++it)
	{
		// 1a. initialize the visited map for each city to false
		visited[*it] = false;
		// 1b. initialize the predecessors map for each city to "-1"
		predecessors[*it] = "-1";
	}	

	// initialization step; put the source vertex on the list to explore
	yetToExplore.push_back(city1);
	visited[city1] = true;

	cout << "Starting at " << city1 << endl;	
	cout << "Looking for " << city2 << endl;
	
	cout << "DEPTH FIRST" << endl;

	// launch the depth first search
	// if it succeeds, we say that it worked
	if (depthFirstSearch(g, cities, city2, visited, yetToExplore, predecessors))
	{
		cout << "path exists! between " << city1 << " and " << city2 << endl;
		string node = city2; 
		// now, use the predecessors map to print the predecessors we took
		string pathThroughCities = city2;
		size_t length = 0;
		while (predecessors.find(node) != predecessors.end() && predecessors[node] != "-1")
		{
			++length;
			string ancestor = predecessors[node];
			pathThroughCities = ancestor + ", \n" + pathThroughCities;
			node = ancestor;
		}
		cout << "path length (in hops): " << length << endl;
		cout << "path is: " << pathThroughCities << endl;
    
		return true;
	}

	// if it fails, we admit there is no path

	cout << "no path exists! between " << city1 << " and " << city2 << endl;
	return false;
}

// check whether a path exists via breadth first search.
bool doesBFSPathExist(const Graph& g, const vector<string>& cities, const string& city1, const string& city2)
{
	vector<string> yetToExplore;
	map<string, bool> visited;
	map<string, string> predecessors;
	
	// check for the special case that we are already there
	if (city1.compare(city2) == 0)
	{
		return true;
	}

    // initialize both the visited map and the neighbors map
	vector<string>::const_iterator it;
	for (it = cities.begin(); it != cities.end(); ++it)
	{
		// 2a. initialize the visited map for each city to false (write this line)
		visited[*it] = false;
		// 2b. initialize the predecessors map for each city to "-1" (write this line)
		predecessors[*it] = "-1";
	}

	// initialization step; push the source vertex onto the stack
	yetToExplore.push_back(city1);
	visited[city1] = true;

	cout << "Starting at " << city1 << endl;
	cout << "Looking for " << city2 << endl;
	
//	cout << "Starting at " << v1.getLatDegrees() << " " << v1.getLatMinutes() << " " << v1.getLongDegrees() << " " << v1.getLongMinutes() << endl;

	
	// launch the breadth first search
	// if it succeeds, we say that it worked
	cout << "BREADTH FIRST" << endl;
	if (breadthFirstSearch(g, cities, city2, visited, yetToExplore, predecessors))
	{
		cout << "path exists! between " << city1 << " and " << city2 << endl;

        // now, use the predecessors map to print the path we took
		string node = city2;
		string pathThroughCities = city2;
		size_t length= 0;
		while (predecessors.find(node) != predecessors.end() && predecessors[node] != "-1")
		{
			string ancestor = predecessors[node];
			pathThroughCities = ancestor + ", \n" + pathThroughCities;
			node = ancestor;
			++length;
		}
		cout << "path length (in hops): " << length << endl;
		cout << "path is: " << pathThroughCities << endl;
		return true;
	  
	}
	// if it fails, we admit there is no path
	cout << "no path exists! between " << city1 << " and " << city2 << endl;
	return false;
}

// LOGIC: if there's still stuff in the yetToExplore vector,
// we pop one city off the end, then check it to see if it's the destination
// if yes, we are done (return true)
// if no, we push all its unvisited neighbors on the back of the yetToExplore vector
// for each neighbor, we store the city we came from to get there
// and then return the result of depth first search again.
// If the vector is empty, we give up (return false)
bool depthFirstSearch(const Graph& g, const vector<string>& cities, 
	const string& destinationVertex, map<string, bool>& visited, vector<string>& yetToExplore, 
	map<string, string>& predecessors)
{
	// if there is still stuff in yetToExplore
	if (!yetToExplore.empty())
	{
		// 3a. get the first element of the vector (write this line), and store as a string called
		// explorationVertex
		string explorationVertex = yetToExplore.back();
		
		// 3b. remove the first element of the vector (write this line)
		yetToExplore.erase(yetToExplore.end());
		
		// 3c. if the first element matches the destination, we're done; return true (write these lines)
		if(explorationVertex.compare(destinationVertex) == 0)
			return true;
		
		// else, we loop over all the cities in the vector of cities to check for edges to 
		// explorationVertex
	    vector<string>::const_iterator it;
	    for (it = cities.begin(); it != cities.end(); ++it)
	    {
			string neighboringVertex = *it;
			// 3d. if graph g contains an edge between the vertex we're exploring
			// and a neighboring vertex, and this other vertex is unexplored, put
			// it on the list of stuff to explore (write this line)
			if (g.containsEdge(explorationVertex, neighboringVertex) && !visited[neighboringVertex])
			{
				// 3e. add the neighbor to the yetToExplore vector (write this line)
				yetToExplore.push_back(neighboringVertex);
				// 3f. mark it as visited (write this line)
				visited[neighboringVertex] = true;
				// 3g. leave a breadcrumb; explorationVertex is the predecessor of neighboring vertex
				// (write this line)
				predecessors[neighboringVertex] = explorationVertex;
			}
	    }
	    
	    // recursive call (nothing to write)
	    return depthFirstSearch(g, cities, destinationVertex, visited, yetToExplore, predecessors);
	}
    return false;
}

// LOGIC: if there's still stuff in the yetToExplore vector,
// we pop one city off the front, then check it to see if it's the destination
// if yes, we are done (return true)
// if no, we push all its unvisited neighbors onto the back of yetToExplore
// for each neighbor, we store the city we came from to get there
// and then return the result of depth first search again.
// If the vector is empty, we give up (return false)
bool breadthFirstSearch(const Graph& g, const vector<string>& cities, const string& destinationVertex, map<string, bool>& visited, vector<string>& yetToExplore, map<string, string>& predecessors)
{
	if (!yetToExplore.empty())
	{
		// 4a. get the first element of the vector (write this line), and store as a string called
		// explorationVertex
	    string explorationVertex = yetToExplore.front();
	    // 4b. remove the first element of the vector (use erase when you write this line)
		yetToExplore.erase(yetToExplore.begin());
	    // 4c. if the last element matches the destination, we're done; return true (write these lines)
		if(explorationVertex.compare(destinationVertex) == 0)
			return true;
		// else, we loop over all the cities in the vector of cities to check for edges to 
		// explorationVertex
	    vector<string>::const_iterator it;
		for (it = cities.begin(); it != cities.end(); ++it)
	    {
			string neighboringVertex = *it;
			
			// 4d. if graph g contains an edge between the vertex we're exploring
			// and a neighboring vertex, and this other vertex is unexplored, put
			// it on the list of stuff to explore (write this line)
			if (g.containsEdge(explorationVertex, neighboringVertex) && !visited[neighboringVertex])
			{
				// 4e. add the neighbor to the yetToExplore vector (write this line)
				yetToExplore.push_back(neighboringVertex);
				// 4f. mark it as visited (write this line)
				visited[neighboringVertex] = true;
				// 4g. leave a breadcrumb; explorationVertex is the predecessor of neighboring vertex
				// (write this line)
				predecessors[neighboringVertex] = explorationVertex;
			}
	    }
	    return breadthFirstSearch(g, cities, destinationVertex, visited, yetToExplore, predecessors);
	}

    return false;
}
    
// read in 775 cities and their latitude/longitude
// cities within the distance limit of each other are connected by edges
void initGraphFromFile(Graph& g, vector<string>&cities, const string& fileName, double limit)
{
	string line;
	int latDegrees, latMinutes, longDegrees, longMinutes;
	ifstream fileToRead;
	char compassDir;
	// open the data file of cities, cities.txt, with openForRead (write this line)
	fileToRead.open(fileName.c_str());
	unsigned int count = 0;
	// keep reading until all cities have been added (nothing to write)
	while (isMoreStuffThere(fileToRead) && count < 775)
	{
	    // build the city name from the file, lines to write are below
	    do
	    {
			// we'll initialize a city, a state, and a country from this line (nothing to write)
			string cityName = "";
			string countryName = "";
			string stateName = "";
			// 5a. grab latitude coordinates and compass direction (write about 3 lines)
			// cout << these to make sure they are right and then take the cout line out when they work
			fileToRead >> latDegrees >> latMinutes >>compassDir;
			//>> longDegrees >> longMinutes >> compassDir;
			//cout << latDegrees << latMinutes <<compassDir;
			
			if (compassDir == 'S')
			{
				latDegrees = -latDegrees;
				latMinutes = -latMinutes;
			
				// 5b. make latDegrees and latMinutes negative (write 2 lines)
			}
			
			// 5c. hop over a space using ignore() (write this line)
			fileToRead.ignore();
			
			fileToRead >> longDegrees >> longMinutes >>compassDir;
			// 5d. grab longitude coordinates and compass direction (about 3 lines)
			
			if (compassDir == 'W')
			{
				longDegrees = -longDegrees;
				longMinutes = -longMinutes;
				// 5e. make longDegrees and longMinutes negative (write 2 lines)
			}
			
			// 5f. hop over a space using ignore() (write this line)
			fileToRead.ignore();
			
			char c;
			bool stateExists = true;
			do
			{
				// 5g. check for a space in the city name and add it to the city (write 2 lines)				
				if (fileToRead.peek() == ' ')
					cityName += ' ';

				// read in a character (nothing to write)
				fileToRead >> c;
				
				// if the character is a boundary marker, (nothing to write)
				if (c == ',' || c == '|')
				{
					// if it's a '|', then there's no state (nothing to write)
					if (c == '|')
						stateExists = false;
					// otherwise, hop over this character with ignore() (write one line)
					else
						fileToRead.ignore();
					// exit the loop if you found a comma or a | (nothing to write)
					break;
				}
				else
				{
					// add this to the city name (nothing to write)
					cityName += c;
				}
			} while (true);
			
			if (stateExists)
			{
				do
				{
					// 5h. read in the state including spaces, and break out of the loop at the '|' (write a few lines)
					if(fileToRead.peek() == '|')
					{
						fileToRead.ignore();
						break;
					}
					fileToRead >> c;
					stateName += c;				
					
					
				} while (true);
			}

			do
			{
				// exit if you see a newline (nothing to write)
				if (fileToRead.peek() == '\n' || fileToRead.peek() == '\r')
					break;
				// 5i. read in the country including spaces, and break out of the loop at the '|' (write a few lines)
				fileToRead >> c;
				countryName += c;
			} while (true);
			
			string uniqueName;
			if (stateExists)
				uniqueName = cityName + "|" + stateName + "|" + countryName;
			else
				uniqueName = cityName + "|" + countryName;
			// put this name on the list (nothing to write)
			cities.push_back(uniqueName);
			// add a vertex for this to the Graph (nothing to write)
			Vertex city = Vertex(uniqueName, latDegrees, latMinutes, 
				longDegrees, longMinutes, cityName, stateName, countryName);
			g.addVertex(city);

			++count;

		} while (count < 775);
	}
	// now we are done with our file
	fileToRead.close();

	cout << "Closed the file" << endl;
	// now we compute the edges that are within the allowed distance
	vector<string>::iterator it1, it2;
	Vertex v1, v2;
	for (it1 = cities.begin(); it1 != cities.end(); ++it1)
	{
	    for (it2 = cities.begin(); it2 != cities.end(); ++it2)
	    {
			if (it1 != it2)
			{
				v1 = g.getVertex(*it1);
				v2 = g.getVertex(*it2);
				// compute the great circle distance between the vertices (nothing to write)
				double d = greatCircleDistance(v1, v2);

				// 6a. if it's within the limit, add the edge (2 lines)
				if(d < limit)
				{
					g.addEdge(v1.getName(), v2.getName(), Edge(d));

				}
			}		
	    }
    }
}

// function defined by Michael Main for input data (nothing to write)
void openForRead(ifstream& f, const char filename[])
{
	f.open(filename);
	if (f.fail())
	{
		cerr << "Could not open input file." << endl;
		exit(0);
	}
}

// function defined by Michael Main for input data (nothing to write)
bool isMoreStuffThere(ifstream& f)
{
	return (f && (f.peek() != EOF));
}

int main( )
{
	double limit;

	// random initializer (nothing to write)
	srand(time(NULL));

	Graph g;
	vector<string> cities;

	// choose a distance limit for your plane (nothing to write)
    cout << "Enter a distance limit ";
	cin >> limit;
	
	// initialize the graph (nothing to write)
	initGraphFromFile(g, cities, "cities.txt", limit);
    string sourceVertex, destinationVertex;
	
	int destinationIndex;
	int sourceIndex;
	// 7a. randomly initialize starting vertex to one of the 775 (one line)
	sourceIndex = rand()%775 + 1;
	// 7b. initialize the destination vertex to a different one of the 775 (3 lines with the do)
	do
	{
		destinationIndex = rand()%775 + 1;;
	} while (destinationIndex == sourceIndex);
	
	
	sourceVertex = cities[sourceIndex];
	
	destinationVertex = cities[destinationIndex];

	// check for path with depth first search; if it exists, run breadth first search (nothing to write)
	if (doesDFSPathExist(g, cities, sourceVertex, destinationVertex))
		doesBFSPathExist(g, cities, sourceVertex, destinationVertex);
		
    return EXIT_SUCCESS;
}
