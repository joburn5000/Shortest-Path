#include "City.h"


City::City() {
    city_name = "";
    latitude = 0.0;
    longitude = 0.0;
}
City::City(string name, double latitude_, double longitude_) {
    city_name = name;
    latitude = latitude_;
    longitude = longitude_;
}
string City::getName() {
    return city_name;
}

double City::getLatitude() const {
    return latitude;
}
double City::getLongitude() {
    return longitude;
}
double City::getDistance(City target) {
    return sqrt(pow((latitude - target.getLatitude()), 2) + pow((longitude - target.getLongitude()), 2));
};
void City::add_adj_city(City new_city) {
    adj_cities.push_back(new_city);
    //cout<<adj_cities.size()<<" ";
}
void City::print_adj_cities() {
    
    cout<<city_name<<" has "<<adj_cities.size()<<": ";
    for (City adj : adj_cities) {
        cout<<adj.getName()<< " ";
    }
    cout<<endl;
    
}
vector<City> City::get_adj_cities() {
    return adj_cities;
}
void City::delete_adj_cities() {
    adj_cities.clear();
}


bool City::operator<(City const & other) const {
    if (latitude < other.getLatitude()) {
        return 1;
    } else {
        return 0;
    }
}
bool City::operator>(City const & other) const {
    if (latitude >= other.getLatitude()) {
        return 1;
    } else {
        return 0;
    }
}
