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
        void printGraph() {
        for (int i = 0; i < numNodes; i++) {
            cout << i << " --> ";
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << "(" << adjList[i][j].first << ", " << adjList[i][j].second << ") ";
            }
            cout << endl;
        }
        }
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1, 12);
    g.addEdge(0, 2, 8);
    g.addEdge(0, 3, 21);
    g.addEdge(2, 3, 6);
    g.addEdge(2, 6, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 5);
    g.addEdge(3, 4, 9);
    g.addEdge(4, 5, 7);
    g.addEdge(5, 6, 6);

    g.printGraph();
    return 0;
}