#include "graph.h"

int getTime() { return 1; }

int main()
{
    GraphAdjList graph(11, Graph::ConnectionType::directed);

    graph.addEdge(1, 2);
    graph.addEdge(2, 5);
    graph.addEdge(5, 9);

    graph.addEdge(1, 4);
    graph.addEdge(4, 8);

    graph.addEdge(1, 3);
    graph.addEdge(3, 6);
    graph.addEdge(6, 10);

    graph.addEdge(3, 7);

    std::vector<bool> visited(11, false); 

    for (int i = 1; i < 11; ++i) 
    {
        if (!visited[i])
        {
            std::cout << "\nComponent starting from vertex " << i << ": ";
            graph.BFS(i);
            visited[i] = true; 
        }
    }

    bool stronglyConnected = graph.isStronglyConnected();
    std::cout << "\n\nIs graph strongly connected: " << (stronglyConnected ? "true" : "false") << std::endl;

    int nodesInLevel3 = graph.numberOfNodesInLevel(3);
    std::cout << "Number of nodes in level 3: " << nodesInLevel3 << std::endl;

    return 0;
}

#ifdef TIME_LOG_ENABLED
	int startTime = getTime();
#endif	

#ifdef TIME_LOG_ENABLED
	int endTime = getTime();
	int diff = endTime - startTime;
	std::cout << "Time used for BFS: " << diff << std::endl;
#endif
