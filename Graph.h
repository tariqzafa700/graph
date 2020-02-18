#include <sstream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include "GraphInf.h"
#include "Iterable.h"
#include "EdgeParser.h"

using namespace std;

#ifndef __GRAPH_H__
#define __GRAPH_H__
class Graph : public GraphInf
{
    protected:
      int nVertices;
      int nEdges;
      list<Edge> edgeList;
      vector<list<Edge>> adjList;
    public:
      Graph(int v);
      Graph(stringstream& in, const EdgeParser& parser);
      virtual void addEdge(const Edge& edge);
      auto adj(int v) -> decltype(make_iterable(adjList[v].begin(), adjList[v].end()));
      void init();
      int getNVertices();
      int getNEdges();
      void print();
};
#endif