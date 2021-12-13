#include <iostream>
#include "data_processing.h"
using namespace std;

int main() {
    data_processing d;
    vector<vector<string>> data = d.process_data("data/uscities.csv");
    vector<City> city_list = d.create_city_list(data);
    map<City, vector<City>> adj = d.connect_cities(city_list);
    vector<Edge> edge_list = d.get_edges();
    Graph graph(city_list, edge_list);
    graph.add_map(adj);

    graph.print_adj_cities();
    graph.print_algorithm_results(city_list[0]);

    return 0;
}