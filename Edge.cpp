#include "Edge.h"

Edge::Edge(int startVert, int endVert, int weight) : src(startVert), dest(endVert), weight(weight)
{
    
}

int Edge::compareTo(Edge& other)
{
    return this->weight > other.weight;
}
      
int Edge::getSrc() const
{
    return this->src;
}

int Edge::getDest() const
{
    return this->dest;
}

int Edge::getWeight() const
{
    return this->weight;
}

ostream& operator << (std::ostream& os, const Edge& obj)
{
   os << obj.getSrc() << "," << obj.getDest() << "->" << obj.getWeight() << '\t';
   return os;
}