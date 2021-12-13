#include "../data_processing.h"
#include "../City.h"
#include "../Graph.h"
#include "TESTCASE.h"
#include <iostream>
using namespace std;

int main() {
    test TESTCASE;
    data_processing d;
    vector<vector<string>> data = d.process_data("data/uscities.csv");
    vector<City> city_list = d.create_city_list(data);
    map<City, vector<City>> adj = d.connect_cities(city_list);
    vector<Edge> edge_list = d.get_edges();
    Graph graph(city_list, edge_list);
    
    //TESTCASE.check_connections(city_list, adj);
    /*for (int i = 0; i < city_list.size(); i++) {
        cout<<i+1<<") ";
        cout<<city_list[i].getName()<<" has "<<adj[city_list[i]].size()<<" : ";
        for (City city : adj[city_list[i]]) {
            cout<<city.getName()<<" ";
        }
        cout<<endl;
    }*/
    //TESTCASE.check_get_distance(city_list[0], city_list[1]);
    //TESTCASE.check_get_distance(city_list[5], city_list[6]);
    //TESTCASE.check_add_adj_city(city_list[0]);
    TESTCASE.compare_algorithm_results(city_list, graph, city_list[0], adj);
    // FW Test:
    /*
    vector<vector<double>> FW_results = graph.FW(adj);
    bool flag = true;
    for (int j = 0; j < city_list.size()-1; j++) {
        cout<<city_list[j].getName()<<": ";
        for (int i = 1; i < city_list.size(); i++) {
            cout<<FW_results[j][i]<<" ";
            if (FW_results[j][i] > 100) flag = false;
            //City origin = city_list[0];
            //City destination = city_list[i];
            //cout<<origin.getName()<<" to "<<destination.getName()<<": "<<FW_results[0][i]<<endl;
        }
        cout<<endl;
    }*/
    

    //Dijkstra's Test:
    /*
    map<City, pair<City, double>> dijkstras_results = graph.dijkstras(city_list[0], adj);
    for (City city : city_list) {
        cout<<city.getName()<<" ";
        cout<<dijkstras_results[city].second<<endl;
    }
    */
    
    // BFS Test:
    /*
    for (unsigned i = 0; i < city_list.size(); i++) {
        double BFS_result = graph.BFS(graph, city_list[0], city_list[i], adj);
        cout<<"Distance from "<<city_list[0].getName()<<" to "<<city_list[i].getName()<<": "<<BFS_result<<endl;
    }
    */
    //TESTCASE.check_algorithm_results(graph);
    return 0;
};