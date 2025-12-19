#include <iostream>
#include "graph.h"
#include "pathfinder.h"

int main() {
    Graph graph(6);

    graph.addEdge(0, 1, 1.0);
    graph.addEdge(1, 2, 1.0);
    graph.addEdge(2, 3, 1.0);
    graph.addEdge(3, 4, 1.0);
    graph.addEdge(4, 5, 1.0);
    graph.addEdge(0, 5, 10.0);

    PathFinder finder(graph);
    auto path = finder.runAStar(0, 5);

    std::cout << "Path: ";
    for (int node : path) {
        std::cout << node << " ";
    }

    std::cout << "\nDistance: " << finder.pathDistance();
    std::cout << "\nNodes visited: " << finder.nodesVisited() << "\n";

    return 0;
}
