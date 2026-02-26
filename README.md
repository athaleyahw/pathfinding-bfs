# Overview

This project is a C++ console application that demonstrates pathfinding on a 2D grid.
The program finds the shortest path between a starting point and a destination while avoiding obstacles.

The project focuses on algorithmic thinking, data structures, and problem-solving using C++.

#Technologies Used

C++

STL (vector, queue)

2D arrays

Breadth-First Search (BFS)

 How It Works

The grid is represented as a 2D array:

0 = free space

1 = obstacle

The algorithm starts from a given start position.

It explores neighboring cells using Breadth-First Search.

The shortest valid path to the destination is calculated.

The final grid is printed to the console with the path marked.

 Algorithm Used

Breadth-First Search (BFS)
BFS guarantees the shortest path in an unweighted grid by exploring all possible paths level by level.

This project demonstrates:

Queue-based traversal

Boundary checking

Visited-state tracking

Grid-based movement logic

 How to Run

Compile the program:

g++ main.cpp -o pathfinding

Run the executable:

./pathfinding
Example Output

S = Start

E = End

# = Obstacle

* = Path

S * * # .
. # * # .
. # * * *
. . . # E
