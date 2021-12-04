/*
#include "City.h"
#include "Graph.h"
#include "Edge.h"*/
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

void process_data(string filename) {
    // open file for reading
    fstream fin;
    fin.open(filename, ios::in);

    // extract data
    vector<string> data;
    string d;
    getline(fin, d);
    for (int i = 0; i < 50; i++) {
        string line;
        getline(fin, line);
        data.push_back(line);
        cout<<line<<endl;
    }
    cout<<"hello"<<endl;
    // build graph
    // connect nodes according to procedure
}