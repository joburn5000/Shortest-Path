#pragma once
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;

class City {
	public:
		City();
		City(string name, double latitude_, double longitude_);
		string getName();
        double getLatitude();
        double getLongitude();
        double get_distance(City target);
        void add_adj_city(City new_city);
		// map<string, double> getAdj();
	private:
		string city_name;
        double latitude;
        double longitude;
        vector<City> adj_cities;
		// map<string, double> adj_cities;
};
