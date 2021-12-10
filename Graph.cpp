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
#include <queue>
#include <map>
#include <limits>

#include "Graph.h"
using namespace std;
 
vector<vector<double>> Graph::FW() {
    vector<vector<double>> dist;
    for (unsigned i = 0; i < cities_.size(); i++) {
        vector<double> inner;
        for (unsigned j = 0; j < cities_.size(); j++) {
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
    vector<vector<double>> output;
    map<City, double> d;
    vector<City> p;
    double infinity = 99999999;
    for(City v : cities_) {
        d[v] = infinity;
        p.push_back(v);
    }
    d[s] = 0;
    priority_queue<double> Q; //use  queue
    for(City x : s.get_adj_cities()) {
        Q.push(s.getDistance(x));
    }
    City G;
    for(unsigned i = 0; i < G.get_adj_cities().size(); i++) { // what is G
        City u; // @todo change
        //City u = Q.removeMin(); // throwing error
        for(City v : u.get_adj_cities()) {
            if(u.getDistance(v) + d[u] < d[v]) {
                d[v] = u.getDistance(v) + d[u];
                for(City x : v.get_adj_cities()) { // add neighbors of this to queue to repeat for next step
                    Q.push(v.getDistance(x));
                }
                p[getIndex(v)] = u; // used to be p[v]
            }
        }
    }
    return output;
}
    
vector<vector<double>> Graph::BFS (Graph G, City s, City e) {
    vector<vector<double>> output;
    queue<City> q; // queue
    vector<City> path;
    map<City, bool> explored;
    map<City, bool> previous;
    for (City v : cities_) {
        explored[v] = false;
        previous[v] = NULL;
    }
    explored[s] = true;
    q.push(s);
    while (!q.empty()) {
        City v; // change
        if (v.getName() == e.getName()) {
            path.push_back(v);
            // return path; path isn't correct type
        }
        q.pop();
        for (City adjCity: cities_[getIndex(v)].get_adj_cities()) { // made changes to fix bug, not sure if this is what you wanted
            if (!explored[v]) {
                explored[v] = true;
                q.push(v);
            }
        }
    }
    return output;
}
 
// Helper function
int Graph::getIndex(City c) {
    for (unsigned i = 0; i < cities_.size(); i++) {
        if (cities_[i].getName() == c.getName()) return i;
    }
    return -1;
}
