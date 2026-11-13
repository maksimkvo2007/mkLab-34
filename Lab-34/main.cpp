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
    }
};

int main() {
    Graph g(7);
    return 0;
}