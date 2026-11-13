#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int numNodes;
    vector<vector<pair<int, int>>> adjList;

    Graph(int n) {
        numNodes = n;
        adjList.resize(n);
        void addEdge(int u, int v, int w) {
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1, 12);
    g.addEdge(0, 2, 8);
    return 0;
}