#ifndef CSCI1300_VERTEX_H
#define CSCI1300_VERTEX_H

#include <string>
#include <cstring>

namespace elizabeth_white_stl_vector_adjacency_matrix
{
	class Vertex
    {
		public:
	
			Vertex( );
			Vertex(const std::string& vertexName);
			Vertex(const std::string& VertexName, int latDegrees, int latMinutes,
				int longDegrees, int longMinutes, const std::string& city, 
				const std::string& state, const std::string& country);
			const std::string& getName() const;
			const std::string& getCity() const;
			const std::string& getState() const;
			const std::string& getCountry() const;
			int getLatDegrees() const;
			int getLongDegrees() const;
			int getLatMinutes() const;
			int getLongMinutes() const;
			void setCity(const std::string& newName);
			void setState(const std::string& newState);
			void setCountry(const std::string& newCountry);
			void setLatDegrees(const int latDegrees);
			void setLongDegrees(const int longDegrees);
			void setLatMinutes(const int latMinutes);
			void setLongMinutes(const int longMinutes);
			
			bool getBadness();
			void setBadness(const bool& badOrNot);
		
		private:
			std::string uniqueName;
			std::string cityName;
			std::string stateName;
			std::string countryName;
			bool bad;
			int degreesLong;
			int degreesLat;
			int minutesLong;
			int minutesLat;
	};
}
#endif
