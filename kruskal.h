#pragma once
#include <vector>

namespace graphs {

struct Edge {
    int v1;
    int v2;
    int weight;
};

std::vector<Edge> kruskalSkeleton(std::vector<std::vector<std::pair<int, int>>>& graph);

}
