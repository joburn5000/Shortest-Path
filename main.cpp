#include <iostream>
#include "data_processing.h"
using namespace std;

int main() {
    data_processing d;
    vector<vector<string>> data;
    data = d.process_data("data/uscities.csv");
    vector<City> city_list;
    city_list = d.create_city_list(data);

    d.connect_cities(city_list);
    //city_list[0].print_adj_cities();
    for (int i = 0; i < city_list.size(); i++) {
        cout<<i+1<<") ";
        city_list[i].print_adj_cities();
    }
    d.check_connections(city_list);
    return 0;
}