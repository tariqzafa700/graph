#include "EdgeParserWeightedImpl.h"

list<Edge> EdgeParserWeightedImpl::parse(int nEdges, stringstream& ss) const
{
    list<Edge> edgeList;
    string startVertex, endVertex, weight;
    for (auto i = 0; i < nEdges; ++i)
    {
        ss >> startVertex >> endVertex >> weight;
        edgeList.push_back(Edge(atoi(startVertex.c_str()), atoi(endVertex.c_str()), atoi(weight.c_str())));
    }
    return edgeList;
}