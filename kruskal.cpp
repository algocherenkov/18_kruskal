#include "kruskal.h"
#include <algorithm>

namespace {
struct {
    bool operator() (graphs::Edge& a, graphs::Edge& b)
    {
        return a.w < b.w;
    }
} edgeComparator;

    std::vector<graphs::Edge> createSortedEdges(std::vector<std::vector<std::pair<int, int>>>& graph)
    {
        std::vector<int> used;
        used.resize(graph.size(), 0);
        std::vector<graphs::Edge> result;

        int i = 0;
        for(const auto& vertex: graph)
        {
            for(const auto& edge: vertex)
            {
                if(used[edge.first])
                    continue;
                result.emplace_back(i, edge.first, edge.second);
            }

            used[i] = 1;
            i++;
        }

        std::sort(result.begin(), result.end(), edgeComparator);
        return result;
    }

    void changeParent(int vertex, int newParent, std::vector<int>& parent)
    {
        int value = parent[vertex];
        for(auto& v: parent)
            if(v == value)
                v = parent[newParent];
    }
}

namespace graphs {
std::vector<Edge> kruskalSkeleton(std::vector<std::vector<std::pair<int, int> > > &graph)
{
    std::vector<graphs::Edge> result;

    std::vector<int> parent;
    parent.resize(graph.size());
    int i = 0;
    for(auto& vertex: parent)
    {
        vertex = i;
        i++;
    }

    auto edges = createSortedEdges(graph);
    for(const auto& edge: edges)
    {
        if(parent[edge.v1] != parent[edge.v2])
        {
            changeParent(edge.v2, edge.v1, parent);
            result.push_back(edge);
        }
    }

    return result;
}
}

