#pragma once
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;

class City {
	public:
		City();
		City(string name, int latitude_, int longitude_);
		string getName();
        int getLatitude();
        int getLongitude();
        int get_distance(City target);
        void add_adj_city(City new_city);
		// map<string, double> getAdj();
	private:
		string city_name;
        int latitude;
        int longitude;
        vector<City> adj_cities;
		// map<string, double> adj_cities;
};
