/*
class Graph { #Graph.h
Public:
	Graph();
	Void init(ifstream file);
	
	Std::vector<Edge> getEdges();
	Std::vector<City> getCities();
	Private:
		std::vector<std::vector<double>> FW();
		std::vector<std::vector<double>> dijkstras(); // change vectors
		std::vector<Edge> edges_;
		std::vector<City> cities_;
} # Graph.cpp
*/

#include <vector>
#include "Edge.h"
#include "City.h"

std::vector<std::vector<double>> FW() {
	double[cities_.size()][cities_.size()] dist;
	For (double[] arr : dist) {
		For (double d : arr) {
			D = std::numeric_limits<double>::infinity();
		}
	}
	For (City c : cities_) {
		Dist[getIndex(c)][getIndex(c)] = 0.0;
}
For (Edge e : edges_) {
	dist[getIndex(e.getStart())][getIndex(e.getEnd())] = e.getDist();
}
For (City k : cities_) {
	For (City u : cities_) {
		For (City v : cities_) {
			If (dist[getIndex(u)][getIndex(v)] > dist[getIndex(u)][getIndex(k)] + dist[getIndex(k)][getIndex(v)]) {
dist[getIndex(u)][getIndex(v)] =  dist[getIndex(u)][getIndex(k)] + dist[getIndex(k)][getIndex(v)];
			}
		}
	}
}
return dist;
}

std::vector<std::vector<double>>  dijkstras(Graph G, City s) { // use vectors
	double[] d;
	City[] p;
	float infinity = std::numeric_limits<float>::infinity();
	for(City v : cities_) {
		d[v] = infinity;
		p[v] = NULL;
	}
	d[s] = 0;
	PriorityQueue Q; (use std:: queue)
	Q.buildHeap(G.getCities());
	Graph T;
	for(int i = 0; i < G.getCities().size(); i++) {
		City m = Q.removeMin();
		T.add(m);
		for(City v : v.getAdj()) {
			if(cost(u,v) + d[u] < d[v]) {  // the cost(u,v) would be the distance between cities, which is the double part of the adjacent city map
				d[v] = cost(u,v) + d[u];
				p[v] = m;
}
		}
	}
}

