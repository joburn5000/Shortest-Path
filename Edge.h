#pragma once
#include "City.h"

class Edge {
	public:
        Edge();
		Edge(City s, City e);
		City getStart();
		City getEnd();
		double getDist();
	private:
		City start_;
		City end_;
		double dist_;
};