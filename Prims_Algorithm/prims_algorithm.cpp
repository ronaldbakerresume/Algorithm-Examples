#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(vector<int>& key, vector<bool>& inMST, int V) {
    int minKey = INT_MAX, minVertex = -1;
    for (int v = 0; v < V; ++v) {
        if (!inMST[v] && key[v] < minKey) {
            minKey = key[v];
            minVertex = v;
        }
    }
    return minVertex;
}

void primsMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V, -1); // Store the MST
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    key[0] = 0; // Start from vertex 0

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinVertex(key, inMST, V);
        inMST[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    int V = graph.size();
    primsMST(graph, V);

    return 0;
}

