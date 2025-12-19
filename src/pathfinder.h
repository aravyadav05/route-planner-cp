#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <vector>
#include <queue>
#include "graph.h"

enum class Algorithm {
    ASTAR,
    DIJKSTRA
};

class PathFinder {
public:
    PathFinder(const Graph& graph);

    std::vector<int> run(int start, int goal, Algorithm algo);

    int nodesVisited() const;
    double pathDistance() const;

private:
    const Graph& graph;
    int visitedCount;
    double totalDistance;

    double heuristic(int a, int b) const;
};

#endif
