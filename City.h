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
        double getLatitude() const;
        double getLongitude();
        double getDistance(City target);

        bool operator<(City const & other) const;
        bool operator>(City const & other) const;
	private:
		string city_name;
        double latitude;
        double longitude;
};
