Abstract

This program takes the top 50 cities in the USA and uses
the algorithms Floyd-Warshall, Dijkstra, and BFS to find
the shortest path between any 2 cities.

 
The code has the following files:

Data

- The data for the code is found in the data folder
- The data is a CSV file, downloaded from
  https://simplemaps.com/data/us-cities
- The CSV file, called "uscities.csv" contains
  information about cities in America including city name,
  latitude, longitude. It contained more information as well,
  but those three were the only ones we needed
- In our code, we selected the top 50 cities according
  to population

data_processing.h

- contains a list of edges and function to get edges
- process_data outputs a 2D matrix of strings given a 
  csv file
- create_city outputs a city given a vector of strings
- create_city_list outputs a list of cities given a
  2D matrix
- connect_cities connects cities together given a list
  of cities. It creates edges and outputs a map that 
  graphs each city to a list of its adjacent cities


City.h

 - Contains the City class which stores the city's name, 
   latitude, and longitude
 - Has functions to get private variables
 - getDistance calculates the distance from this 
   city to another city
   
   
Edge.h

- Contains the Edge class which stores start city, end
  city, and the distance between those cities
- Has functions to get private variables


Graph.h

- Contains the Graph class which stores a list of edges,
  list of cities, and a map that graphs each city to a
  list of its adjacent cities
- Has functions to get private variables and to add a map
- Contains the Floyd Warshall and Dijkstra's algorithms
  and the BFS traversal
- getIndex outputs the index of a given a City

Folders:

- data: contains the csv file and its license
- md files: contains contract, development, goals & proposal,
  README, results, and log
- tests: contains TESTCASE.h TESTCASE.cpp, and test.cpp

Results

- you can access the results given the functions in graph:
- print_adj_cities prints out all the adjacent cities
- compare_algorithm_results prints out side-by-side 
  results of FW, Dijstra, and BFS for a given city as a
  distance from that city to all the other cities

 
 
 In order to run the algorithms and traversals, one must first
 process data:
 
 - create an instance of data_processing class
 - run process_data given your csv file, creating a 2D matrix
 - run create_city_list using the 2D matrix as input
 - run connect_cities using the city list as input, creating a
   map that graphs each city to its adjacent cities
 - run get_edges() and store as an edge list
 
 
 Now the data is processed. you should have a city list, an
 edge list, and a map that graphs each city to its adjacent 
 cities. Next, create a graph:
 
 - create an instance of the graph class using your city list
   and edge list as input
 - run add_map using the map as input to add map to the graph


You can now run any function in the graph class, including the
algorithms, traversal, and print adjacent cities. To show the
results of running the algorithms, use compare_algorithm_results
You also have the ability to use the graph to run test cases, 
as described below.


Building and running code:

- Included in the file is a Makefile that allows for easy
  compilation of the code. To use the available commands
  "make" and "make test," install Makefile Tools (instructions 
  here: 
  https://devblogs.microsoft.com/cppblog/now-announcing-makefile-support-in-visual-studio-code/
- The Makefile will create executables main.exe after running
  make and test.exe after running make test. These can be run
  using ./main and ./test respectively
- You can also compile and run the code without the Makefile,
  using whatever method is easiest for you. On how to build cpp 
  files:
  https://www.tutorialspoint.com/How-to-compile-and-run-the-Cplusplus-program
  * Be sure to compile all files, including those in the tests 
  folder
 
 Algorithm Input and Output Information
 
 FW(): Floyd-Warshall's Algorithm)
 
 - Input: nothing. All the information is found within the class
   that contains FW(), the Graph class 
 - Output: a 2D matrix of doubles (distances) To get a distance,
   get the indexes of your start and end city using the helper
   function getIndex(city). You can find any distance by accessing
   fw[i]\[j] where i is the start index and j is the end index and
   fw is the result of calling FW()
 
 dijkstras(City s): Dijkstra's Algorithm
 
 - Input: City s which is the city of origin
 - Output: a map that graphs a city to distance. You can access
   the distance from the origin city to any other city by
   calling d[c] where c is the destination city and d is the
   result of calling dijkstras(City s)
   
 BFS(City s, City e): Breadth-First Traversal
 
 - Inputs: City s and City e which are the start and end cities
   respectively
 - Output: a double (distance) from City s to City e


 To run tests, first procss data and create a graph by following
 instructions in (2). Then do the following:
 
 - create an instance of the test class
 - run any test case within the test class


TESTCASES and test.cpp are found in the tests folder There are 
5 test cases, including:

 - check_connections: checks all cities are connected both ways 
   and that there are no duplicates
 - check_get_distance: checks that the distance calculator works
 - check_add_adj_city: check that the size of adj cities goes 
   up when you add a city
 - check_FW_dijkstras: compares the results from FW and Dikjstra's
 - check_BFS: compares the results from BFS to FW and Dikjstra's


Collaborators: Andrew O'Connel and Steven Beallis
