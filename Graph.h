#pragma once
#include <iostream>
#include <fstream>
#include "Edge.h"
#include "City.h"

#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <limits>
#include <iostream>
#include <functional>
using namespace std;

class Graph {
	public:
		Graph();
        Graph(vector<City> cities, vector<Edge> edges);
		vector<Edge> getEdges();
		vector<City> getCities();
		vector<vector<double> > FW();
		map<City, pair<City, double> > dijkstras(City s); // change vectors
        vector<vector<double> > BFS(Graph G, City s, City e);
		int getIndex(City c);
	private:
		vector<Edge> edges_;
		vector<City> cities_;
};
