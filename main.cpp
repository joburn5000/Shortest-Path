#include <iostream>
#include "data_processing.h"
using namespace std;

int main() {
    data_processing data;
    data.process_data("data/uscities.csv");
    return 0;
}