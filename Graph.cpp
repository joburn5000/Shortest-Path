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
 
vector<vector<double> > Graph::FW() {
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
 
map<City, pair<City, double> > Graph::dijkstras(City s) { // use vectors
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
    while(!Q.empty()) { // what is G
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
    
double Graph::BFS (City s, City e) {
    double dist = 0;
    queue<City> q; // queue
    vector<City> path;
    map<City, bool> explored;
    map<City, City> previous;
    for (City v : cities_) {
        explored[v] = false;
        previous[v] = City();
    }
    explored[s] = true;
    q.push(s);
    while (!q.empty()) {
        City v = q.front();
        if (v.getName() == e.getName()) break;
        q.pop();
        for (City adjCity: adj[v]) {
            if (!explored[adjCity]) {
                explored[adjCity] = true;
                q.push(adjCity);
                previous[adjCity] = v;
            }
        }
    }
    City* temp = &e;
    while (temp->getName() != s.getName()) {
        City prevCity = previous[e];
        dist += temp->getDistance(prevCity);
        *temp = prevCity;
    }
    return dist;
}
// Helper function
int Graph::getIndex(City c) {
    for (unsigned i = 0; i < cities_.size(); i++) {
        if (cities_[i].getName() == c.getName()) return i;
    }
    return -1;
}

void Graph::add_map(map<City, vector<City>> adj_) {
    adj = adj_;
}
map<City, vector<City>> Graph::get_map() {
    return adj;
}

void Graph::print_algorithm_results(City start) {
    cout<<"_________________________________________________________"<<endl;
    cout<<"compare_algorithm_results for "<<start.getName()<<endl;
    cout<<"_________________________________________________________"<<endl;
    vector<vector<double>> FW_results = FW();
    vector<City> city_list = cities_;
    bool flag = true;
    int start_index = getIndex(start);
    map<City, pair<City, double>> Dijkstra_results = dijkstras(start);
    for (int i = 1; i < city_list.size(); i++) {
        cout<<start.getName()<<" to "<<city_list[i].getName()<<":"<<endl;
        cout<<"FW:  "<<69*FW_results[start_index][i]<<" miles"<<endl;
        cout<<"Dik: "<<69*Dijkstra_results[city_list[i]].second<<" miles"<<endl;
        cout<<"BFS: "<<69*BFS(start, city_list[i])<<" miles"<<endl;
    }
    cout<<"_________________________________________________________"<<endl;
}
void Graph::print_adj_cities() {
    cout<<"_________________________________________________________"<<endl;
    cout<<"Connections between cities:"<<endl;
    cout<<"_________________________________________________________"<<endl;
    for (int i = 0; i < cities_.size(); i++) {
        cout<<i+1<<") ";
        cout<<cities_[i].getName()<<" has "<<adj[cities_[i]].size()<<" connections: ";
        for (int j = 0; j < adj[cities_[i]].size(); j++) {
            if (j == adj[cities_[i]].size()-1) {
                cout<<cities_[j].getName()<<endl;
            }
            else {
                cout<<cities_[j].getName()<<", ";
                if (j == adj[cities_[i]].size()-2) cout<<"and ";
            }
        }
    }
    cout<<"_________________________________________________________"<<endl;
}
