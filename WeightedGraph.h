#include "Graph.h"
#include "Comparable.h"

#ifndef __WEIGHTEDGRAPH_H__
#define __WEIGHTEDGRAPH_H__
class WeightedGraph : public Graph
{
    public:
      WeightedGraph(stringstream& ss, const EdgeParser& );
      virtual void print();
};
#endif