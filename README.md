# Route Planner in C++

A graph-based route planning system implemented in C++ that computes shortest
paths using **A\*** and **Dijkstra** algorithms.  
The project is built with **CMake** and demonstrates algorithmic trade-offs
using performance metrics and path visualization.

---

## Highlights
- Implemented **A\*** and **Dijkstra** shortest-path algorithms in C++
- Compared algorithms using **distance** and **nodes visited** metrics
- Added **text-based path visualization** for computed routes
- Designed modular graph abstractions
- Built and managed the project using **CMake** and **Git**

---

## Features
- Graph abstraction using adjacency lists
- A\* shortest path algorithm with heuristic
- Dijkstra algorithm (heuristic-free)
- Performance metrics:
  - Total path distance
  - Number of nodes explored
- Text-based visualization of the computed path
- Modular and extensible C++ design
- CMake-based build system

---

## Algorithms Implemented

| Algorithm  | Heuristic | Optimal | Notes |
|-----------|-----------|---------|------|
| A*        | Yes       | Yes     | Faster with good heuristic |
| Dijkstra  | No        | Yes     | Explores more nodes |

---

## Sample Output

[A*]
Path: 0 -> 1 -> 2 -> 3 -> 4 -> 5
Distance: 5
Nodes visited: 6

[Dijkstra]
Path: 0 -> 1 -> 2 -> 3 -> 4 -> 5
Distance: 5
Nodes visited: 6

This output shows that both algorithms find the same shortest path, while A*
can reduce the search space using heuristics on more complex graphs.

---

## Project Structure

route-planner-cp/
├── src/
│ ├── graph.cpp
│ ├── graph.h
│ ├── pathfinder.cpp
│ ├── pathfinder.h
│ └── main.cpp
├── assets/
│ └── map.osm
├── CMakeLists.txt
└── README.md

---

## Build & Run

### Requirements
- C++17 compatible compiler
- CMake ≥ 3.10

### Build
```bash
mkdir build
cd build
cmake ..
cmake --build .
