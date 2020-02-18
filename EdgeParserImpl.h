#include "EdgeParser.h"

#ifndef __EDGEPARSERIMPL_H__
#define __EDGEPARSERIMPL_H__
class EdgeParserImpl : public EdgeParser
{
    public:
      EdgeParserImpl();
      virtual list<Edge> parse(int nEdges, stringstream& ss) const;
    private:
      
};
#endif