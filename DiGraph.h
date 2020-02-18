#include "Graph.h"

#ifndef __DIGRAPH_H__
#define __DIGRAPH_H__
class DiGraph : public Graph {
    public:
        DiGraph(stringstream&, const EdgeParser&);
        virtual void addEdge(const Edge& edge);
};
#endif