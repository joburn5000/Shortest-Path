
#include "City.h"
#include "Graph.h"
//#include "Edge.h"
#pragma once
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class data_processing {
public:
    // converts the data in csv file to a vector of vectors
    vector<vector<string>> process_data(string filename);
    // creates a city using a vector of information
    City create_city(vector<string> cells);
    // creates a list of cities
    vector<City> create_city_list(vector<vector<string>> data);
    // connects all cities together
    void connect_cities(vector<City> city_list); // @todo: only connect some cities together
private:
    // vector<vector<string>> data;
};