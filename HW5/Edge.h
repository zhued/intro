#ifndef CSCI1300_EDGE_H
#define CSCI1300_EDGE_H

#include <cstring>

namespace elizabeth_white_stl_vector_adjacency_matrix
{
	class Edge
    {
		public:
			Edge();
			Edge(const double& cost);
			Edge(const Edge& anotherEdge);
			bool exists() const;
			void setCost(const double& newCost);
			const double& getCost() const;
			void erase();
			bool getBadness() const;
			void setBadness(const bool& badOrNot);
		private:
			
			double cost;
			bool bad;
	};
}
	
#endif
