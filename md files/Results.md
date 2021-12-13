The final project has been successfully completed. The project used a data set 
containing latitude and longitude coordinates for US cities, which was parsed 
using an algorithm to process the data in the spreadsheet. It was then organized 
into a graph, with the nodes of the graph being cities, and edges representing 
the distance between cities. We had to ensure that the graph was fully connected 
so that you could reach any node in it starting from any other node. We wrote 2 
algorithms to find the shortest path between two nodes, as well as a general BFS 
traversal. The algorithms that we wrote are Floyd-Warshall’s algorithm and 
Dijkstra’s algorithm. In our implementation, Dijkstra’s algorithm returns a map 
of a City to a pair of a city and a double. The first City in the map represents 
the target city, and in the pair, the city represents the previous city in the 
path to it and the double represents the distance to that city from the start. 
Dijkstra’s returns the shortest distance to every city from its starting node. 
The algorithm adds nodes to a priority queue that is ordered with the smallest 
element first, and pops off the smallest value. It then looks at each neighbor
node and the distance to it, and if this calculated distance is smaller than the 
preexisting distance, replaces it. The Floyd-Warshall's algorithm returns a 2D vector
of doubles representing the shortest distances between all pairs of cities. The vector
is initialized with an infinite value and with zeroes on all pairs of identical cities.
Afterwards, it looks at all pairs of cities, along with all other cities as anchors that
could bypass a lack of edge between the pair in figuring out the shortest distance.
Both these algorithms return the distance to the target node accounting for the weight of 
each edge (which is the distance between cities). However, when BFS finds the 
shortest path between 2 cities, it does not account for this. It simply finds 
the path with the least number of nodes between them, even if there are very 
large distances between these nodes. Both of the algorithms and the BFS traversal 
run pretty quickly, and the results given by both algorithms are the same for 
any possible choice of cities. As a group, we discovered that there really are 
many different algorithms and approaches that can be taken to solve the same issue. 
This can be seen in the many differences between the two algorithms. Yet, despite 
these differences, they both produce identical results. This suggests that even if 
you feel you have a very efficient implementation of some solution to a problem, 
there may exist a different and possibly better implementation of the same problem. 
Because of this, it is always important to make sure that the solution you come up 
with is efficient and works correctly. Overall, we managed to complete this project 
and the goals we outlined at the beginning successfully. We managed to create 2 working 
algorithms that successfully found the shortest path between two nodes (cities) in a 
graph, and they both run quickly. We were able to communicate well with one another, 
and offered help to each other whenever it was needed.
