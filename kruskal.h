#pragma once
#include <vector>

namespace graphs {

struct Edge {
    Edge(int vertex1, int vertex2, int weight):
        v1(vertex1),
        v2(vertex2),
        w(weight)
    {}

    int v1 {-1};
    int v2 {-1};
    int w{-1};
};

std::vector<Edge> kruskalSkeleton(std::vector<std::vector<std::pair<int, int>>>& graph);

}
