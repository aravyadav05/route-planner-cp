#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <vector>
#include <queue>
#include "graph.h"

class PathFinder {
public:
    PathFinder(const Graph& graph);

    std::vector<int> runAStar(int start, int goal);

    int nodesVisited() const;
    double pathDistance() const;

private:
    const Graph& graph;

    int visitedCount;
    double totalDistance;

    double heuristic(int a, int b) const;
};

#endif
