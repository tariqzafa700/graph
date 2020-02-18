#include "EdgeParserImpl.h"

EdgeParserImpl::EdgeParserImpl()
{
    
}

list<Edge> EdgeParserImpl::parse(int nEdges, stringstream& ss) const
{
    list<Edge> edgeList;
    string startVertex, endVertex;
    for (auto i = 0; i < nEdges; ++i)
    {
        ss >> startVertex >> endVertex;
        edgeList.push_back(Edge(atoi(startVertex.c_str()), atoi(endVertex.c_str())));
    }
    return edgeList;
}