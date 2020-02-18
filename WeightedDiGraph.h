#include "DiGraph.h"
#include "Comparable.h"

#ifndef __WEIGHTED_DIGRAPH_H__
#define __WEIGHTED_DIGRAPH_H__
class WeightedDiGraph : public DiGraph
{
    public:
      WeightedDiGraph(stringstream& ss, const EdgeParser& );
      virtual void print();
};
#endif