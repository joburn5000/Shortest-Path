main: main.cpp data_processing.cpp City.cpp Edge.cpp Graph.cpp
	g++ main.cpp data_processing.cpp City.cpp Edge.cpp Graph.cpp -o main



test: tests/test.cpp data_processing.cpp City.cpp Edge.cpp tests/TESTCASE.cpp Graph.cpp
	g++ tests/test.cpp data_processing.cpp City.cpp Edge.cpp tests/TESTCASE.cpp Graph.cpp -o test

