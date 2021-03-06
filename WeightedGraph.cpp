#include "WeightedGraph.h"

WeightedGraph::WeightedGraph(stringstream& ss, const EdgeParser& parser) : Graph(ss, parser)
{

}

void WeightedGraph::print()
{
    int count = 0;
    for_each(adjList.begin(), adjList.end(), [&count](list<Edge>& each) {
        cout << "List [" << count++ << "] ";
        copy(each.begin(), each.end(), ostream_iterator<Edge>(std::cout, " "));
        cout << '\n';
    });
}