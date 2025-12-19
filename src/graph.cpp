#include "graph.h"

Graph::Graph(int n) {
    adj.resize(n);
}

void Graph::addEdge(int from, int to, double weight) {
    adj[from].push_back({to, weight});
}

const std::vector<Graph::Edge>& Graph::neighbors(int node) const {
    return adj[node];
}

int Graph::size() const {
    return adj.size();
}
