#include "DiGraph.h"

void DiGraph::addEdge(const Edge& edge)
{
    int startVertex = edge.getSrc();
    int endVertex = edge.getDest();
    int weight = edge.getWeight();
    list<Edge>& iter1 = adjList[startVertex];
    iter1.push_back(edge);
    nEdges++;
}

DiGraph::DiGraph(stringstream& ss, const EdgeParser& parser) : Graph(ss, parser)
{

}