
A C++ implementation of a maze-solving system that finds a valid path between a start and destination point using graph traversal algorithms. The project demonstrates the use of Breadth First Search (BFS), Depth First Search (DFS), path reconstruction, and grid-based traversal techniques.

## Features

- Find paths in a 2D maze environment
- Breadth First Search (BFS) traversal
- Depth First Search (DFS) traversal
- Parent tracking for path reconstruction
- Obstacle and boundary validation
- Coordinate-based path visualization
- Efficient grid exploration using queues and recursion

## Concepts Used

- Graph Traversal
- Breadth First Search (BFS)
- Depth First Search (DFS)
- Queue Data Structure
- Recursion
- Backtracking
- Path Reconstruction
- 2D Arrays
- Coordinate Navigation

## Maze Representation

| Symbol | Meaning |
|----------|----------|
| S | Start Position |
| E | End Position |
| 1 | Walkable Cell |
| 0 | Blocked Cell |

## Algorithm Workflow

1. Read the maze dimensions and layout.
2. Locate the start (`S`) and destination (`E`) cells.
3. Explore the maze using BFS or DFS.
4. Store parent information for each visited cell.
5. Reconstruct the final path from destination to source.
6. Display the path coordinates and path length.

## Sample Input

```text
5 5
S1110
00110
11110
01111
0001E
```

## Sample Output

```text
Path found! Length: 9
Path coordinates:
(0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (3,3) -> (3,4) -> (4,4)
```

## Project Structure

```text
├── final_code.cpp
├── README.md
└── sample_inputs/
```

## How to Run

### Compile

```bash
g++ final_code.cpp -o maze_solver
```

### Execute

```bash
./maze_solver
```

### Windows

```bash
g++ final_code.cpp -o maze_solver.exe
maze_solver.exe
```

## Learning Outcomes

- Understanding graph traversal algorithms
- Comparing BFS and DFS approaches
- Implementing shortest path search in grids
- Working with recursive and iterative algorithms
- Applying data structures to real-world navigation problems

## Technologies Used

- C++
- STL Queue
- STL Vector
- Recursion
- Graph Algorithms

## Future Improvements

- Weighted pathfinding using Dijkstra's Algorithm
- Graphical maze visualization
- Multiple source and destination support
- Dynamic maze generation

---


