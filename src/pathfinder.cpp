#include "pathfinder.h"
#include <limits>
#include <cmath>
#include <algorithm>


PathFinder::PathFinder(const Graph& g)
    : graph(g), visitedCount(0), totalDistance(0.0) {}

double PathFinder::heuristic(int a, int b) const {
    // Simple heuristic: absolute difference
    return std::abs(a - b);
}

std::vector<int> PathFinder::runAStar(int start, int goal) {
    int n = graph.size();

    std::vector<double> gScore(n, std::numeric_limits<double>::infinity());
    std::vector<int> parent(n, -1);
    std::vector<bool> visited(n, false);

    using State = std::pair<double, int>; // (fScore, node)
    std::priority_queue<State, std::vector<State>, std::greater<State>> openSet;

    gScore[start] = 0.0;
    openSet.push({heuristic(start, goal), start});

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
                double fScore = tentative + heuristic(next, goal);
                openSet.push({fScore, next});
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

int PathFinder::nodesVisited() const {
    return visitedCount;
}

double PathFinder::pathDistance() const {
    return totalDistance;
}

