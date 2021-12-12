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
    vector<Edge> edge_list = d.connect_cities(city_list);
    Graph graph(city_list, edge_list);
    
    //TESTCASE.check_connections(city_list);
    //TESTCASE.check_get_distance(city_list[0], city_list[1]);
    //TESTCASE.check_get_distance(city_list[5], city_list[6]);
    //TESTCASE.check_add_adj_city(city_list[0]);
    vector<vector<double>> FW_results = graph.FW();
    for (int j = 0; j < city_list.size()-1; j++) {
        cout<<city_list[j].getName()<<": ";
        for (int i = 1; i < city_list.size(); i++) {
            cout<<FW_results[j][i]<<" ";
            
            //City origin = city_list[0];
            //City destination = city_list[i];
            //cout<<origin.getName()<<" to "<<destination.getName()<<": "<<FW_results[0][i]<<endl;
        }
        cout<<endl;
    }
    
    //for (City origin : city_list) {
    map<City, pair<City, double>> dijkstras_results = graph.dijkstras(city_list[0]);
    for (City city : city_list) {
        cout<<city.getName()<<" ";
        cout<<dijkstras_results[city].second<<endl;
    }
    //}
    
    //TESTCASE.check_algorithm_results(graph);
    return 0;
};