output: main.o
	g++ main.o -o main

main.o: main.cpp
	g++ -c main.cpp

data_processing.o: data_processing.cpp data_processing.h
	g++ -c data_processing.cpp

clean:
	rm *.o main