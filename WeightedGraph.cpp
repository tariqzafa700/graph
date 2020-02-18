#include "WeightedGraph.h"

WeightedGraph::WeightedGraph(stringstream& ss, const EdgeParser& parser) : Graph(ss, parser)
{

}

void WeightedGraph::print()
{
    int count = 0;
    for_each(adjList.begin(), adjList.end(), [&count](list<pair<int, int>>& each) {
        cout << "List [" << count++ << "] ";
        for_each(each.begin(), each.end(), [](pair<int, int> item) {
            cout << item.first << ',' << item.second << '\t';
        });
        cout << '\n';
    });
}