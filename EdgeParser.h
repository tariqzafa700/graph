#include <sstream>
#include <list>
#include "Edge.h"

using namespace std;

#ifndef __EDGEPARSER_H__
#define __EDGEPARSER_H__
class EdgeParser
{
    public:
      virtual list<Edge> parse(int nEdges, stringstream& ss) const = 0;
};
#endif