#include "WeightedDiGraph.h"

WeightedDiGraph::WeightedDiGraph(stringstream& ss, const EdgeParser& parser) : DiGraph(ss, parser)
{

}

void WeightedDiGraph::print()
{
    int count = 0;
    for_each(adjList.begin(), adjList.end(), [&count](list<Edge>& each) {
        cout << "List [" << count++ << "] ";
        copy(each.begin(), each.end(), ostream_iterator<Edge>(std::cout, " "));
        cout << '\n';
    });
}