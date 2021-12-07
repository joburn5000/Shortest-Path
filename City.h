#pragma once
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class City {
	public:
		City();
		City(string name, double latitude_, double longitude_);
		string getName();
        double getLatitude();
        double getLongitude();
        double getDistance(City target);
        void add_adj_city(City new_city);
        void delete_adj_cities();
        vector<City> get_adj_cities();
        void print_adj_cities();
		// map<string, double> getAdj();
	private:
		string city_name;
        double latitude;
        double longitude;
        vector<City> adj_cities;
		// map<string, double> adj_cities;
};
