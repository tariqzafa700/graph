#include "Graph.h"

Graph::Graph(int v)
{
    nVertices = v;
    nEdges = 0;
    adjList.reserve(v);
    adjList.resize(v);
}

Graph::Graph(stringstream& ss, const EdgeParser& edgeParser)
{
    string numVerts, startVerex, endVertex, numEdges;
    int n;
    nEdges = 0;
    if (ss)
    { 
        ss >> numVerts;
        nVertices = atoi(numVerts.c_str());
        ss >> numEdges;
        adjList.reserve(nVertices);
        adjList.resize(nVertices);
        edgeList = edgeParser.parse(atoi(numEdges.c_str()), ss);
    }
}

void Graph::init()
{
    for_each(edgeList.begin(), edgeList.end(), [this](const Edge& verts) {
        addEdge(verts);
    });
}

void Graph::addEdge(const Edge& edge)
{
    int startVertex = edge.getSrc();
    int endVertex = edge.getDest();
    int weight = edge.getWeight();
    list<Edge>& iter1 = adjList[startVertex];
    iter1.push_back(Edge(edge.getSrc(), edge.getDest(), edge.getWeight()));
    list<Edge>& iter2 = adjList[endVertex];
    iter2.push_back(Edge(edge.getDest(), edge.getSrc(), edge.getWeight()));
    nEdges++;
}

auto Graph::adj(int v) -> decltype(make_iterable(adjList[v].begin(), adjList[v].end()))
{
    return make_iterable(adjList[v].begin(), adjList[v].end());
}

int Graph::getNEdges()
{
    return nEdges;
}

int Graph::getNVertices()
{
    return nVertices;
}

void Graph::print()
{   
    int count = 0;
    for_each(adjList.begin(), adjList.end(), [&count](list<Edge>& each) {
        cout << "List [" << count++ << "] ";
        copy(each.begin(), each.end(), ostream_iterator<Edge>(std::cout, " "));
        cout << '\n';
    });
}