#pragma once
#include <iostream>
#include <fstream>
#include "Edge.h"
#include "City.h"
using namespace std;

class Graph {
	public:
		Graph();
	
		vector<Edge> getEdges();
		vector<City> getCities();
	private:
		vector<vector<double>> FW();
		vector<vector<double>> dijkstras(); // change vectors
        vector<vector<double>> BFS(Graph G, City s, City e);
		int getIndex(City c);
		vector<Edge> edges_;
		vector<City> cities_;
};
