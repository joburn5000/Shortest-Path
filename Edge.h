class Edge { #Edge.h
	Public:
		Edge(City s, City e);
		City getStart();
		City getEnd();
		Double getDist();
	Private:
		City start_;
		City end_;
		Double dist_;
} #Edge.cpp
