# Computing-Principles-for-Electrical-Engineers

This repository showcases the homework assigments I completed for the data structures and algorithms course I took during my graduate studies. Assignment descriptions can be made summarized when appropriate.

### [Final Project](https://github.com/rohitpenumarti/Computing-Principles-for-Electrical-Engineers/blob/master/Final-Project/final.cc)

For the final project for this course, I was tasked with implementing common algorithms used for graph based applications specifically useful for map applications. This included:
 - Autocompleting given partial location names and including all locations containing the given prefix
 - Retrieving the position of a location given the name
 - Computing the shortest path as a list of location IDs between two different locations given their names using Dijkstra's shortest path algorithm
 - Computing the shortest path as a list of location IDs between two different locations given their names using the Bellman-Ford shortest path algorithm
 - Travelling Salesman Problem: Computing the shortest path between a list of locations that visits each location and returns to the starting location. Solved using brute force, backtracking, and 2-opt heuristic. Returns list of location IDs.
 - Cycle Detection: determines if there is a cycle path between four points of a square-shaped subgraph
 - Topological Sort: given a vector of locations, it sorts the nodes according to given dependencies
 - Find the k closest points to a given location and k

All problems solved with C++.
