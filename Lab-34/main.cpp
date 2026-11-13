#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Graph {
public:
    int numNodes;
    vector<vector<pair<int, int>>> adjList;
    vector<string> names;

    Graph(int n) {
        numNodes = n;
        adjList.resize(n);
        names.resize(n);

        void addEdge(int u, int v, int w) {
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
        }

       void printGraph() {
        cout << "Network Topology:" << endl;
        for (int i = 0; i < numNodes; i++) {
            cout << "Junction " << i << " (" << names[i] << ") connects to:" << endl;
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << "  -> " << adjList[i][j].first << " with capacity " << adjList[i][j].second << endl;
            }
        }
        }

        void DFS(int start) {
        vector<bool> visited(numNodes, false);
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            if (!visited[curr]) {
                cout << curr << " ";
                visited[curr] = true;
            }

            for (int j = 0; j < adjList[curr].size(); j++) {
                int next = adjList[curr][j].first;
                if (!visited[next]) {
                    s.push(next);
                }
            }
        }
        cout << endl;
        }
        void BFS(int start) {
        vector<bool> visited(numNodes, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int j = 0; j < adjList[curr].size(); j++) {
                int next = adjList[curr][j].first;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        cout << endl;
        }
    }
};

int main() {
    Graph g(11);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 3, 4);
    g.addEdge(1, 4, 8);
    g.addEdge(2, 5, 6);
    g.addEdge(2, 6, 3);
    g.addEdge(3, 7, 7);
    g.addEdge(4, 7, 2);
    g.addEdge(4, 8, 9);
    g.addEdge(5, 8, 5);
    g.addEdge(5, 9, 4);
    g.addEdge(6, 9, 11);
    g.addEdge(7, 10, 3);
    g.addEdge(8, 10, 6);
    g.addEdge(9, 10, 2);

    vector<string> stopNames = {"Central", "Downtown", "City Hall", "Library", "Campus", "Hospital", "Mall", "Arena", "School", "Park", "Airport"};
    for(int i = 0; i < 11; i++) { 
        g.names[i] = stopNames[i]; 
    }
    g.printGraph();
    g.DFS(0);
    return 0;
}