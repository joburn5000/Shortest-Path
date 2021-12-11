#include "data_processing.h"
#include <string>
#include <sstream>
#include <algorithm>

vector<vector<string>> data_processing::process_data(string filename) {
    // open file for reading
    fstream fin;
    fin.open(filename, ios::in);

    // extract data
    vector<vector<string>> data;
    string d;
    getline(fin, d);
    for (int i = 0; i < 50; i++) {
        // get line
        vector<string> line_data;
        string line, col; getline(fin, line);
        // remove quotation marks (")
        line.erase(remove(line.begin(), line.end(), '\"' ), line.end());
        // add to data vector
        stringstream ss(line);
        while (getline(ss, col, ',')) {
            // add cell to line vector
            line_data.push_back(col);
        }
        // add line vector to data vector
        data.push_back(line_data);
    }
    return data;
}

City data_processing::create_city(vector<string> cells) {
    string city_name = cells[0];
    double latitude = stod(cells[6]);
    double longitude = stod(cells[7]);
    City new_city(city_name, latitude, longitude);
    return new_city;
}

vector<City> data_processing::create_city_list(vector<vector<string>> data) {
    vector<City> city_list;
    for (vector<string> line : data) {
        City new_city = create_city(line);
        city_list.push_back(new_city);
    }
    return city_list;
}
vector<Edge> data_processing::connect_cities(vector<City>& city_list) {
    vector<Edge> edges;
    for (int i = 0; i < city_list.size(); i++) {
        for (int j = 0; j < city_list.size(); j++) {
            int dist = city_list[i].getDistance(city_list[j]);
            if (city_list[i].getName() != city_list[j].getName() && dist < 6) {
                city_list[i].add_adj_city(city_list[j]);
                Edge new_edge(city_list[i], city_list[j]);
                edges.push_back(new_edge);
            }
        }
    }
    for (int i = 0; i < city_list.size(); i++) {
        if (city_list[i].get_adj_cities().size() < 3) {
            for (int j = 0; j < city_list.size(); j++) {
                int dist = city_list[i].getDistance(city_list[j]);
                if (city_list[i].getName() != city_list[j].getName() && dist >= 6 && dist < 10) {
                    city_list[i].add_adj_city(city_list[j]);
                    Edge new_edge(city_list[i], city_list[j]);
                    edges.push_back(new_edge);
                    if (city_list[j].get_adj_cities().size() >= 3) {
                        city_list[j].add_adj_city(city_list[i]);
                        Edge new_edge_2(city_list[j], city_list[i]);
                        edges.push_back(new_edge_2);
                    }
                }
            }
        }
    }
    return edges;
}



