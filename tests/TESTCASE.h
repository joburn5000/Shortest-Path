#pragma once
#include "../City.h"
#include "../Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class test {
    // 1 = good, 0 = something wrong
public:
    test();
    // checks all cities are connected both ways and that there are no duplicates
    bool check_connections(vector<City>& city_list, map<City, vector<City>> adj);
    // checks that the distance calculator works
    bool check_get_distance(City a, City b);
    // check that the size of adj cities goes up when you add a city
    bool check_add_adj_city(City a, map<City, vector<City>> adj);
    // compares the results from FW and Dikjstra's Algorithms
    bool check_algorithm_results(Graph graph, map<City, vector<City>> adj);
    // prints out a comparison
    void compare_algorithm_results(vector<City> city_list, Graph graph, City start, map<City, vector<City>> adj);
private:
};

/*

vector<vector<string>> process_data(string filename);
// creates a city using a vector of information

City create_city(vector<string> cells);
// creates a list of cities
vector<City> create_city_list(vector<vector<string>> data);



void add_adj_city(City new_city); // if there's one more than before
*/