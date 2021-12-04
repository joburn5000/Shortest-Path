#include <map>
#include <string>
#include "Graph.h"
#include "Edge.h"
using namespace std;

class City {
	public:
		City();
		City(string name);
		string getName();
		map<string, double> getAdj();
	private:
		std::string _city_name;
		std::map<string, double> adj_cities;
};
