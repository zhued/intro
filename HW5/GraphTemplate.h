// FILE: GraphTemplate.h (part of the namespace elizabeth_white_adjacency_matrix)
// TEMPLATE CLASS PROVIDED: Graph
//   (a container class for a Graph with Vertex and Edge components)
//
// CONSTRUCTOR for the Graph<Vertex, Edge> class:
//   Graph( )
//     Postcondition: The Graph is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the Graph<Vertex, Edge> class:
//   void clear( )
//     Postcondition: The Graph is empty.
//
//   bool insert(const Item& entry)
//     Postcondition: If an equal entry was already in the Graph, the Graph is
//     unchanged and the return value is false. Otherwise, entry was added
//     to the Graph and the return value is true. This is slightly different than
//     the C++ Standard Library Graph (see Appendix H).
//
//   bool erase(const Item& target)
//     Postcondition: If target was in the Graph, then it has been removed from
//     the Graph and the return value is true. Otherwise the Graph is unchanged
//     and the return value is false.
//
// CONSTANT MEMBER FUNCTIONS for the Graph<Vertex, Edge> class:
//   bool contains(const Item& target) const
//     Postcondition: Returns true if the target is in this Graph; otherwise false.
//
//  bool empty( ) const 
//     Postcondition: Returns true if the Graph is empty; otherwise returns false.
//
// VALUE SEMANTICS for the Graph<Vertex, Edge> class:
//   Assignments and the copy constructor may be used with Graph<Vertex, Edge> objects.
//
// DYNAMIC MEMORY USAGE by the Graph<Vertex, Edge> class:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: The constructors, insert, and the assignment operator.

#ifndef CSCI1300_GRAPH_H
#define CSCI1300_GRAPH_H
#include <cstdlib>   
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

namespace elizabeth_white_stl_vector_adjacency_matrix
{
    class Graph
    {

    public:

        // CONSTRUCTORS and DESTRUCTOR
        Graph( );
        Graph(const Graph& source);
        ~Graph( ) { clear( ); }

        // MODIFICATION MEMBER FUNCTIONS
        Graph& operator =(const Graph& source);
        void clear( );
        bool addVertex(const string& newVertexname);
        bool addVertex(Vertex v);
        bool removeVertex(const string& unwantedVertexName);
        Vertex& getVertex(const string& vertexName);
        Edge& getEdge(const string& fromVertexName, const string& toVertexName);
        bool setEdge(const string& fromVertexName, const string& toVertexName, const Edge& newEdge);
        bool addEdge(const string& fromVertexName, const string& toVertexName, const Edge& newEdge);
    	bool removeEdge(const string& fromVertexName, const string& toVertexName);
        // CONSTANT MEMBER FUNCTIONS
        int countVertices() const;
        int countEdges() const;
        bool containsVertex(const string& vertexName) const;
		bool containsEdge(const string& fromVertexname, const string& toVertexName) const;
        const Vertex& getVertex(const string& vertexName) const;
        const Edge& getEdge(const string& fromVertexName, const string& toVertexName) const;
        bool empty( ) const;

    private:
    
		// CONSTANT MEMBER FUNCTIONS DO NOT CHANGE THE GRAPH
		int getIndex(const string& vertexName) const;
        bool validIndex(const int& vertexIndex) const;
        const Vertex& getVertex(const int& vertexNumber) const;
        const Edge& getEdge(const int& fromVertexNumber, const int& toVertexNumber) const;
        bool containsEdge(const int& fromVertexNumber, const int& toVertexNumber) const;
        bool containsVertex(const int& vertexNumber) const;
        // SUGGESTED FUNCTIONS FOR DEBUGGING
        void print( ) const;
        bool is_valid( ) const;
        
        // NONCONSTANT MEMBER FUNCTIONS CAN ALTER VERTEX OR EDGE DATA
        bool removeVertex(const int& unwantedVertexNumber);
        bool setEdge(const int& fromVertexNumber, const int& toVertexNumber, const Edge& newEdge);
        bool addEdge(const int& fromVertexNumber, const int& toVertexNumber, const Edge& newEdge);
        bool removeEdge(const int& fromVertexNumber, const int& toVertexNumber);
        Vertex& getVertex(const int& vertexNumber);
        Edge& getEdge(const int& fromVertexNumber, const int& toVertexNumber);
        
        
        
        // MEMBER CONSTANTS

        // MEMBER VARIABLES
        bool initialized;
        vector<Vertex> vertices;
        vector<vector<Edge> > edges;
        int vertexCount;
        int edgeCount;
        Vertex badVertex;
        Edge badEdge;
      };
}


#endif
