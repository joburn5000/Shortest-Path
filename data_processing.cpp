#include "data_processing.h"
#include <string>
#include <sstream>
#include <algorithm>

// converts the data in csv file to a vector of vectors
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
            line_data.push_back(col);
        }
        data.push_back(line_data);
    }
    return data;
}