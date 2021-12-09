/*
class Graph { #Graph.h
Public:
	Graph();
	Void init(ifstream file);
	
	Std::vector<Edge> getEdges();
	Std::vector<City> getCities();
	Private:
		vector<vector<double>> FW();
		vector<vector<double>> dijkstras(); // change vectors
		vector<Edge> edges_;
		vector<City> cities_;
} # Graph.cpp
*/

#include <vector>
#include "Edge.h"
#include "City.h"

vector<vector<double>> Graph::FW() {
	vector<vector<double>> dist;
	for (int i = 0; i < cities_.size(); i++) {
		vector<double> inner;
		for (int j = 0; j < cities_.size(); j++) {
			inner.push_back(numeric_limits<double>::infinity());
		}
		dist.push_back(inner);
	}
	for (City c : cities_) {
		dist[getIndex(c)][getIndex(c)] = 0.0;
	}
	for (Edge e : edges_) {
		dist[getIndex(e.getStart())][getIndex(e.getEnd())] = e.getDist();
	}
	for (City k : cities_) {
		for (City u : cities_) {
			for (City v : cities_) {
				if (dist[getIndex(u)][getIndex(v)] > dist[getIndex(u)][getIndex(k)] + dist[getIndex(k)][getIndex(v)]) {
						dist[getIndex(u)][getIndex(v)] =  dist[getIndex(u)][getIndex(k)] + dist[getIndex(k)][getIndex(v)];
				}
			}
		}
	}
	return dist;
}

vector<vector<double>> Graph::dijkstras(City s) { // use vectors
	double[] d;
	double infinity = 99999999;
	City[] p;
	for(City v : cities_) {
		d[v] = infinity;
		p[v] = NULL;
	}
	d[s] = 0;
	PriorityQueue Q; //use  queue
	Q.buildHeap(G.getCities());
	Graph T;
	for(int i = 0; i < G.getCities().size(); i++) {
		City m = Q.removeMin();
		T.add(m);
		for(City v : v.getAdj()) {
			if(cost(u,v) + d[u] < d[v]) {
				d[v] = cost(u,v) + d[u];
				p[v] = m;
}
		}
	}
}

vector<vector<double>> Graph::BFS (Graph G, City s, City e) {
	queue<City> q; # queue
	vector<City> path;
	map<string, bool> explored;
	map<string, bool> previous;
	for (City v : cities_) {
		explored[v] = false;
		previous[v] = NULL;
	}
	explored[s] = true;
	q.push(s);
	while (!q.empty()) {
		If (v == e) {
			path.push_back(v);
			return path;
		}
		q.pop();
		for (City adjCity: Cities[v]) {
			If (!explored[v]) {
				explored[v] = true;
				q.push(v);
		}
	}
}

// Helper function
int Graph::getIndex(City c) {
	for (int i = 0; i < cities_.size(); i++) {
		if (cities_[i] == c) return i;
	}
	return -1;
}

