#include "EdgeParser.h"

#ifndef __EDGEPARSERWEIGHTEDIMPL_H__
#define __EDGEPARSERWEIGHTEDIMPL_H__
class EdgeParserWeightedImpl : public EdgeParser
{
    public:
      virtual list<Edge> parse(int nEdges, stringstream& ss) const;
    private:
};
#endif