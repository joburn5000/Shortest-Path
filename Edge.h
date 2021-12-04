#include "City.h"
#include "Graph.h"
class Edge {
	public:
		Edge(City s, City e);
		City getStart();
		City getEnd();
		double getDist();
	private:
		City start_;
		City end_;
		double dist_;
};
