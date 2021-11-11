Leading Question 

- Given a graph of connected nodes, how can one find the shortest path from start to finish 
using the A* algorithm, dijkstra's algorithm, and BFS traversal. How do these compare and 
what does this teach us about different kinds of efficiency?
- We are hoping to solve the problem of finding the shortest path from one node to another 
node using several types of algorithms / a traversal.


Successful project: 
- We produce a working algorithm that reliably outputs a sequence of from a starting node to an ending node. 
- Optional: Implementing algorithms into a maze shortest path from start to finish.


Dataset
- Our dataset will be from https://simplemaps.com/data/us-cities
- It is a downloadable file that contains the latitude and longitude for towns in America

- Other: Graphs, Priority Queue
- In computer science, a priority queue is an abstract data type similar to a regular queue 
or stack data structure in which each element additionally has a "priority" associated with it. 
In a priority queue, an element with high priority is served before an element with low priority.


Data Acquisition and Processing
- We will download, store, and process data in the following manner: 
- We will doanload the file from https://simplemaps.com/data/us-cities as an excel sheet
- We will then process this data by writing an algorithm to convert the cells in the excel sheet
to nodes, using latitude and longitude to get our datapoints so we can calculate distance
- To handle the messiness of real world data, we will solve issues by researching the common ways 
to tackle them. We will brainstorm as a team in order to come up with our best guess of a solution. 
- If our solution does not work, then we will decide as a team what other solutions may work.


Graph Algorithms 
- A* Manhattan: Manhattan Distance is calculated by the amount of edges required to travel between two 
nodes. On a 2D graph, it is the amount of cardinal movements in order to get to the end.
- A* Pythagorean: Pythagorean Distance takes a diagonal perspective on a 2D graph, it virtually considers
diagonal travel between nodes.
- Dijkstra's algorithm: Dijkstra's Algorithm is based on the principle of relaxation, in which more accurate
values gradually replace an approximation to the correct distance until the shortest distance is reached.


Traversal: 
- BFS: Breadth-first search is an algorithm for searching a tree data structure for a node that satisfies 
a given property. It starts at the tree root and explores all nodes at the present depth prior to moving 
on to the nodes at the next depth level
 

Inputs: A graph of nodes, a start node, and an end node.


Outputs: A graph of the same format consisting of the shortest path from start to end, easing the comparison
between the full graph and the shortest possible path.


Heuristics: Calculating f(n), g(n), updating node neighbor’s f and g values
- Manhattan / Taxicab Heuristic: A taxicab geometry is a form of geometry in which the usual distance function
or metric of Euclidean geometry is replaced by a new metric in which the distance between two points is the 
sum of the absolute differences of their Cartesian coordinates.
- Pythagorean Heuristic: Fundamental relation in Euclidean geometry among the three sides of a right triangle. 
It states that the area of the square whose side is the hypotenuse is equal to the sum of the areas of the 
squares on the other two sides


Timeline
- data acquisition: November 15
- data processing: November 22
- Completion of BFS traversal: November 25
- completion of A* Manhattan: November 29
- Mid-Project Checkin (Nov 29th – Dec 1)
- completion of A* Manhattan: December 3
- Completion of dijkstra's algorithm: December 5
- production of final deliverables: December 8
- Final Project Deliverables (Due Dec 13th)
