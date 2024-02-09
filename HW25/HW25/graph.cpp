#include "graph.h"

GraphAdjList::GraphAdjList(int vertices, ConnectionType type)
    : Graph(vertices, type) {
    m_list.resize(vertices);
}

void GraphAdjList::addEdge(int v, int w) {
    m_list[v].push_back(w);
    if (m_connectionType == ConnectionType::undirected) {
        m_list[w].push_back(v);
    }
}

GraphAdjList GraphAdjList::getTranspose() const {
    GraphAdjList transposedGraph(m_vertices, m_connectionType);

    for (int v = 0; v < m_vertices; ++v) {
        for (int adjacent : m_list[v]) {
            transposedGraph.addEdge(adjacent, v);
        }
    }

    return transposedGraph;
}

void GraphAdjList::BFS(int vertex) 
{
    std::vector<bool> visited(m_vertices, false);
    std::queue<int> queue;
    visited[vertex] = true;
    queue.push(vertex);

    while (!queue.empty())
    {
        int currentVertex = queue.front();
        std::cout << currentVertex << " ";
        queue.pop();

        for (int adjacent : m_list[currentVertex])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push(adjacent);
            }
        }
    }
}

int GraphAdjList::numberOfNodesInLevel(int level) {
    std::vector<bool> visited(m_vertices, false);
    std::queue<int> q;
    q.push(1);
    visited[1] = true;
    int nodesInCurrentLevel = 1;
    int currentLevel = 0;
    int nextLevelNodes = 0;

    while (!q.empty() && currentLevel < level) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int u = q.front();
            q.pop();
            for (int v : m_list[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    nextLevelNodes++;
                }
            }
        }
        currentLevel++;
    }

    return nextLevelNodes;
}

bool GraphAdjList::isStronglyConnected() const {
    if (m_vertices == 0)
        return false;

    std::vector<bool> visited(m_vertices, false);
    std::stack<int> finishOrder;
    for (int i = 0; i < m_vertices; ++i) {
        if (!visited[i]) {
            DFSUtil(i, visited, finishOrder);
        }
    }

    GraphAdjList transposed = getTranspose();

    visited.assign(m_vertices, false);
    while (!finishOrder.empty()) {
        int currentVertex = finishOrder.top();
        finishOrder.pop();
        if (!visited[currentVertex]) 
        {
            transposed.DFSUtilForTranspose(currentVertex, visited);
        }
    }

    for (bool v : visited) {
        if (!v)
            return false;
    }

    return true;
}

void GraphAdjList::DFSUtil(int v, std::vector<bool>& visited, std::stack<int>& finishOrder) const {
    visited[v] = true;

    for (int adjacent : m_list[v]) {
        if (!visited[adjacent]) {
            DFSUtil(adjacent, visited, finishOrder); 
        }
    }

    finishOrder.push(v);
}

void GraphAdjList::DFSUtilForTranspose(int v, std::vector<bool>& visited) const {
    visited[v] = true;

    for (int adjacent : m_list[v]) {
        if (!visited[adjacent]) {
            DFSUtilForTranspose(adjacent, visited);
        }
    }
}
