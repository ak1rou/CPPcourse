#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

class Graph {
public:
    enum class ConnectionType {
        undirected,
        directed
    };

    Graph(int vertices, ConnectionType type = ConnectionType::undirected)
        : m_vertices(vertices), m_connectionType(type) {}

    virtual void addEdge(int v, int w) = 0;
    virtual void BFS(int vertex = 0) {};
    virtual void DFS(int vertex = 0) {};
    virtual int numberOfNodesInLevel(int level) = 0;
    virtual bool isStronglyConnected() const = 0;

protected:
    unsigned int m_vertices;
    ConnectionType m_connectionType;
};

class GraphAdjList : public Graph {
public:
    GraphAdjList(int vertices, ConnectionType type = ConnectionType::undirected);
    void addEdge(int v, int w) override;
    void BFS(int vertex = 0) override;
    int numberOfNodesInLevel(int level) override;
    bool isStronglyConnected() const override;
    GraphAdjList getTranspose() const;
    std::vector<std::list<int>> m_list;

private:
    void DFSUtil(int v, std::vector<bool>& visited, std::stack<int>& finishOrder) const;
    void DFSUtilForTranspose(int v, std::vector<bool>& visited) const;
};