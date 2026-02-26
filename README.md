

Overview

This project is a C++ console application that finds the shortest path between two points on a 2D grid using standard pathfinding algorithms. The program avoids obstacles and prints the shortest valid path from start to end.

Grid Symbols

S = Start position
E = End position

= Obstacle

. = Open path

= Shortest path found

Example Grid Input

S . . # .
. # . # .
. # . . .
. . . # E

Example Output

S * * # .
. # * # .
. # * * *
. . . # E

How It Works

The grid is stored as a 2D vector.
The program searches for the start and end positions.
Breadth-First Search (BFS) is used to explore valid neighboring cells.
Obstacles are avoided during traversal.
The shortest path is reconstructed and marked with *.

Technologies Used

C++
STL (vector, queue, map)
Graph traversal algorithms

Concepts Demonstrated

Shortest path algorithms
Data structures
2D grid traversal
Problem-solving and algorithm design

How to Compile and Run

Compile:

g++ main.cpp -o pathfinding

Run:

./pathfinding
