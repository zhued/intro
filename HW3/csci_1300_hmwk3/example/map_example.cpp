/*
Author: Jeffrey LaMarche

Description: Small example of using STL maps. 
Date: 11/02/12
*/

#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int main()
{
	map<char, int> letters;
	map<char, int>::iterator iter;
	
	cout << endl;
	cout << "Map size at creation: " << letters.size() << endl;
	
	cout << endl << "Now adding \'a\' twice to see what happens..." << endl;
	letters['a'] = 4;
	cout << "Map size after adding key \'a\' once: " << letters.size() << endl;
	letters.insert( pair<char, int> ('a', 4));
	cout << "Map size after adding key \'a\' twice: " << letters.size() << endl;
	
	iter = letters.begin();
	
	cout << endl << "Displaying some info about the first element in the map..." << endl;
	cout << "K = " << iter->first << " and V = " << iter->second << endl;
	
	cout << endl << "Adding another element to the map..." << endl;
	letters['b'] = 6;
	
	iter = letters.find('b');
	cout << "Element with key \'" << iter->first << "\' has a mapped value of " << iter->second << endl;
	cout << endl;
	
	return EXIT_SUCCESS;
}