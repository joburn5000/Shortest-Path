#include "City.h"


City::City() {

}
City::City(string name, int latitude_, int longitude_) {
    city_name = name;
    latitude = latitude_;
    longitude = longitude_;
}
string City::getName() {
    return city_name;
}

int City::getLatitude() {
    return latitude;
}
int City::getLongitude() {
    return longitude;
}
int City::get_distance(City target) {
    return sqrt(pow((latitude - target.getLatitude()), 2) + pow((longitude - target.getLongitude()), 2));
};
