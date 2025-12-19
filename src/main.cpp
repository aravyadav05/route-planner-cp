#include <iostream>
#include "graph.h"
#include "pathfinder.h"
void printPath(const std::vector<int>& path) {
    std::cout << "Path: ";
    for (size_t i = 0; i < path.size(); i++) {
        std::cout << path[i];
        if (i + 1 < path.size()) std::cout << " -> ";
    }
    std::cout << "\n";
}


int main() {
    Graph graph(6);

    graph.addEdge(0, 1, 1.0);
    graph.addEdge(1, 2, 1.0);
    graph.addEdge(2, 3, 1.0);
    graph.addEdge(3, 4, 1.0);
    graph.addEdge(4, 5, 1.0);
    graph.addEdge(0, 5, 10.0);

    PathFinder finder(graph);

auto pathAStar = finder.run(0, 5, Algorithm::ASTAR);
std::cout << "[A*]\n";
printPath(pathAStar);
std::cout << "Distance: " << finder.pathDistance() << "\n";
std::cout << "Nodes visited: " << finder.nodesVisited() << "\n\n";

auto pathDijkstra = finder.run(0, 5, Algorithm::DIJKSTRA);
std::cout << "[Dijkstra]\n";
printPath(pathDijkstra);
std::cout << "Distance: " << finder.pathDistance() << "\n";
std::cout << "Nodes visited: " << finder.nodesVisited() << "\n";


    return 0;
}
