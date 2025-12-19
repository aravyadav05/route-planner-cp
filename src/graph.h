#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    struct Edge {
        int to;
        double weight;
    };

    Graph(int n = 0);

    void addEdge(int from, int to, double weight);
    const std::vector<Edge>& neighbors(int node) const;

    int size() const;

private:
    std::vector<std::vector<Edge>> adj;
};

#endif
