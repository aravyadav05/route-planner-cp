#include "pathfinder.h"

#include <limits>
#include <cmath>
#include <algorithm>

// Constructor
PathFinder::PathFinder(const Graph& g)
    : graph(g), visitedCount(0), totalDistance(0.0) {}

// Heuristic function (used only for A*)
double PathFinder::heuristic(int a, int b) const {
    return std::abs(a - b);
}

// Unified pathfinding function (A* or Dijkstra)
std::vector<int> PathFinder::run(int start, int goal, Algorithm algo) {
    int n = graph.size();

    visitedCount = 0;
    totalDistance = 0.0;

    std::vector<double> gScore(n, std::numeric_limits<double>::infinity());
    std::vector<int> parent(n, -1);
    std::vector<bool> visited(n, false);

    using State = std::pair<double, int>; // (cost, node)
    std::priority_queue<State, std::vector<State>, std::greater<State>> openSet;

    gScore[start] = 0.0;

    double startHeuristic =
        (algo == Algorithm::ASTAR) ? heuristic(start, goal) : 0.0;

    openSet.push({startHeuristic, start});

    while (!openSet.empty()) {
        int current = openSet.top().second;
        openSet.pop();

        if (visited[current]) continue;
        visited[current] = true;
        visitedCount++;

        if (current == goal) break;

        for (const auto& edge : graph.neighbors(current)) {
            int next = edge.to;
            double tentative = gScore[current] + edge.weight;

            if (tentative < gScore[next]) {
                gScore[next] = tentative;
                parent[next] = current;

                double heuristicCost =
                    (algo == Algorithm::ASTAR) ? heuristic(next, goal) : 0.0;

                openSet.push({tentative + heuristicCost, next});
            }
        }
    }

    // Reconstruct path
    std::vector<int> path;
    for (int v = goal; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());

    totalDistance = gScore[goal];
    return path;
}

// Getter: number of visited nodes
int PathFinder::nodesVisited() const {
    return visitedCount;
}

// Getter: total path distance
double PathFinder::pathDistance() const {
    return totalDistance;
}
