#pragma once
#include <iostream>
#include <fstream>
#include "Edge.h"
#include "City.h"
using namespace std;

class Graph {
	public:
		Graph();
		void init(ifstream file);
	
		vector<Edge> getEdges();
		vector<City> getCities();
	private:
		vector<vector<double> > FW();
		vector<vector<double> > dijkstras(); // change vectors
		vector<Edge> edges_;
		vector<City> cities_;
};
