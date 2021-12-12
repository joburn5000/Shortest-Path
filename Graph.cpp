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
#include <utility>
#include <limits>

#include "Graph.h"
using namespace std;

Graph::Graph(vector<City> cities, vector<Edge> edges) {
    cities_ = cities;
    edges_ = edges;
}

vector<Edge> Graph::getEdges() {
    return edges_;
}
vector<City> Graph::getCities() {
    return cities_;
}
 
vector<vector<double> > Graph::FW(map<City, vector<City>> adj) {
    vector<vector<double>> dist(cities_.size(), vector<double>(cities_.size(), 9999));
    for (City c : cities_) {
        dist[getIndex(c)][getIndex(c)] = 0.0;
    }
    for (Edge e : edges_) {
        dist[getIndex(e.getStart())][getIndex(e.getEnd())] = e.getDist();
    }
    for (unsigned k = 0; k < cities_.size(); k++) {
        for (unsigned u = 0; u < cities_.size(); u++) {
            for (unsigned v = 0; v < cities_.size(); v++) {
                if (dist[u][v] > dist[u][k] + dist[k][v]) {
                    dist[u][v] =  dist[u][k] + dist[k][v];
                }
            }
        }
    }
    return dist;
}
 
map<City, pair<City, double> > Graph::dijkstras(City s, map<City, vector<City>> adj) { // use vectors
    map<City, pair<City, double>> output;
    map<City, double> d;
    map<City, City> p;
    double infinity = 99999999;
    for(City v : cities_) {
        d[v] = infinity;
    }
    d[s] = 0;
    
    priority_queue<pair<double, City>, vector<pair<double, City>>, greater<pair<double, City>>> Q; //use  queue
    
    for(City x : adj[s]) {
        pair<double, City> insert(s.getDistance(x), x);
        Q.push(insert);
    }
    
    Q.push(pair<double,City>(0,s));
    for(unsigned i = 0; i < this->getCities().size(); i++) { // what is G
        City u = Q.top().second; // @todo change
        Q.pop();
        for(City w : adj[u]) {
            City v;
            for(City p : cities_) {
                if(w.getName() == p.getName()) {
                    v = p;
                }
            }
            if(u.getDistance(v) + d[u] < d[v]) {
                d[v] = u.getDistance(v) + d[u];
                for(City x : adj[v]) { // add neighbors of this to queue to repeat for next step
                    if((x.getLongitude() != v.getLongitude()) || (x.getLatitude() != v.getLatitude())) {
                        pair<double, City> insert(v.getDistance(x)+d[v], x);
                        Q.push(insert);
                    }
                }
                p[v] = u; // used to be p[v]
            }
        }
    }
    for(City c : cities_) {
        pair<City, double> outputpair;
        outputpair.first = p[c];
        outputpair.second = d[c];
        output[c] = outputpair;
    }
    return output;
}
    
vector<vector<double> > Graph::BFS (Graph G, City s, City e, map<City, vector<City>> adj) {
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
        for (City adjCity: adj[cities_[getIndex(v)]]) { // made changes to fix bug, not sure if this is what you wanted
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
