#include <iostream>
#include "Comparable.h"

using namespace std;

#ifndef __EDGE_H__
#define __EDGE_H__

class Edge : public Comparable<Edge>
{
    public:
      Edge(int startVert, int endVert, int weight = 0);
      virtual int compareTo(Edge& other);
      int getSrc() const;
      int getDest() const;
      int getWeight() const;
      friend ostream& operator<<(std::ostream& os, const Edge& obj);
    private:
      int src;
      int dest;
      int weight;
};
#endif