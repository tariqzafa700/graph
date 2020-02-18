#include "Graph.h"
#include "PriorityQueue.h"

enum class state {
    VISITED,
    UNVISITED,
    VISITING
};

struct node {
    state st = state::UNVISITED;
    int weight = 10000;
};

int getShortestPathValue(Graph& graph, int start, int end)
{
    PriorityQueue<Edge> pq;
    vector<node> visited(graph.getNVertices());
    int i = start;
    while (1)
    {
        visited[i].weight = 0;
        visited[i].st = state::VISITED;
        for(auto lst : graph.adj(i))
        {
            if (visited[lst.getDest()].st != state::VISITED)
            {
                if (lst.getWeight() + visited[i].weight < visited[lst.getDest()].weight)
                {
                    visited[lst.getDest()].weight = lst.getWeight() + visited[i].weight;
                }
                pq.addToPq(lst);
                visited[lst.getDest()].st = state::VISITING;
            }
        }
        
        Edge eject = pq.getNextElement();
        pq.removeFromPq();
        i = eject.getSrc();
        if (i == end)
        {
            break;
        }
    }
    cout << visited[end].weight << endl;
    return visited[end].weight;
}