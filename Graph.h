#include <iostream>
#include <fstream>
#include "Edge.h"
#include "City.h"

class Graph {
	public:
		Graph();
		void init(ifstream file);
	
		std::vector<Edge> getEdges();
		std::vector<City> getCities();
	private:
		std::vector<std::vector<double> > FW();
		std::vector<std::vector<double> > dijkstras(); // change vectors
		std::vector<Edge> edges_;
		std::vector<City> cities_;
};
