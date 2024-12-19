#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(const vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsHelper(graph, neighbor, visited);
        }
    }
}

void dfs(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    dfsHelper(graph, start, visited);
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},  // Node 0 is connected to 1 and 2
        {0, 3},  // Node 1 is connected to 0 and 3
        {0, 4},  // Node 2 is connected to 0 and 4
        {1},     // Node 3 is connected to 1
        {2}      // Node 4 is connected to 2
    };

    cout << "DFS Traversal: ";
    dfs(graph, 0);
    return 0;
}

