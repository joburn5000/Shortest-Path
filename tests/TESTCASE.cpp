#include "TESTCASE.h"

test::test() {

}
bool test::check_connections(vector<City>& city_list) {
    cout<<"_________________________________________________________"<<endl; 
    cout<<"TESTCASE: check_connections"<<endl;
    cout<<"_________________________________________________________"<<endl; 
    map<string, vector<string> > data;
    for (City city : city_list) {
        vector<string> data_line;
        string name = city.getName();
        for (City adj_city : city.get_adj_cities()) {
            data_line.push_back(adj_city.getName());
        }
        data[name] = data_line; 
    }
    bool everything_good = true;
    for (int i = 0; i < city_list.size(); i++) {
        string name = city_list[i].getName();
        vector<City> adj_cities = city_list[i].get_adj_cities();
        for (int j = 0; j < adj_cities.size(); j++) {
            string adj_name = adj_cities[j].getName();
            vector<string> adj_adj_cities = data[adj_name];
            if (find(adj_adj_cities.begin(), adj_adj_cities.end(), name) == adj_adj_cities.end()) {
                cout<<name<<" is not found in "<<adj_name<<"'s adjacent list"<<endl;
                everything_good = false;
            }
        }
    }
    if (everything_good) cout<<"all cities are accounted for at least once"<<endl;
    bool no_duplicates = true;
    for (City city : city_list) {
        vector<string> adj_cities = data[city.getName()];
        if (adjacent_find(adj_cities.begin(), adj_cities.end()) != adj_cities.end()) {
            no_duplicates = false;
            cout<<"there is a duplicate in "<<city.getName()<<"'s adjacent list"<<endl;
        }
    }
    if (no_duplicates) cout<<"there are no duplicates in the adjacent city list"<<endl;
    if (everything_good && no_duplicates) {
        cout<<"=> test passed"<<endl;
        cout<<"_________________________________________________________"<<endl;
        return 1;
    }
    else {
        cout<<"=> test failed"<<endl;   
        cout<<"_________________________________________________________"<<endl;
        return 0;
    }
    
}


bool test::check_get_distance(City a, City b) {
    cout<<"_________________________________________________________"<<endl; 
    cout<<"TESTCASE: check_get_distance"<<endl;
    cout<<"_________________________________________________________"<<endl;
    double lat_a = a.getLatitude();
    double long_a = a.getLongitude();
    double lat_b = b.getLatitude();
    double long_b = b.getLongitude();
    double expected_distance = sqrt(pow(lat_a-lat_b,2)+pow(long_a-long_b,2));
    double calculated_distance = a.getDistance(b);
    cout<<"calculating the straight-shot pythagorean distance from"<<endl;
    cout<<a.getName()<<" to "<<b.getName()<<"..."<<endl;
    cout<<"expected distance: "<<expected_distance<<endl;
    cout<<"calculated distance: "<<calculated_distance<<endl;
    if (expected_distance == calculated_distance) {
        cout<<"=> test passed"<<endl;
        cout<<"_________________________________________________________"<<endl;
        return 1;
    }
    else {
        cout<<"=> test failed"<<endl;
        cout<<"_________________________________________________________"<<endl;
        return 0;
    }
}
bool test::check_add_adj_city(City a) {
    cout<<"_________________________________________________________"<<endl; 
    cout<<"TESTCASE: check_add_adj_city"<<endl;
    cout<<"_________________________________________________________"<<endl;
    unsigned original_size = a.get_adj_cities().size();
    a.add_adj_city(a);
    unsigned final_size = a.get_adj_cities().size();
    cout<<"original number of adj cities: "<<original_size<<endl;
    cout<<"number after adding a city:    "<<final_size<<endl;
    if (final_size-original_size == 1) {
        cout<<"=> test passed"<<endl;
        cout<<"_________________________________________________________"<<endl;
        return 1;
    }
    else {
        cout<<"=> test failed"<<endl;
        cout<<"_________________________________________________________"<<endl;
        return 0;
    }
}