#include "Iterable.h"
#include "Edge.h"

#ifndef __GRAPH_INTF_H__
#define __GRAPH_INTF_H__
class GraphInf
{
    virtual void addEdge(const Edge& edge) = 0;
    virtual void print() = 0;
};
#endif