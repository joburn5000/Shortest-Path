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

double City::getLatitude() {
    return latitude;
}
double City::getLongitude() {
    return longitude;
}
double City::get_distance(City target) {
    return sqrt(pow((latitude - target.getLatitude()), 2) + pow((longitude - target.getLongitude()), 2));
};
void City::add_adj_city(City new_city) {
    adj_cities.push_back(new_city);
}
