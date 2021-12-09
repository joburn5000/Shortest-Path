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
   map<City><double> d;
   vector<City> p;
   double infinity = 99999999;
   for(City v : cities_) {
       d.insert(v, infinity);
       p.push_back(v);
   }
   d[s] = 0;
   priority_queue<double> Q; //use  queue
   for(City x : s.getAdj()) {
       Q.push(s.getDistance(x));
   }
   for(int i = 0; i < G.getCities().size(); i++) {
       City u = Q.removeMin();
       for(City v : u.getAdj()) {
           if(u.getDistance(v) + d[u] < d[v]) {
               d[v] = u.getDistance(v) + d[u];
               for(City x : v.getAdj()) { // add neighbors of this to queue to repeat for next step
                   Q.push(v.getDistance(x));
               }
               p[v] = u;
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
