#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},  // Node 0 is connected to 1 and 2
        {0, 3},  // Node 1 is connected to 0 and 3
        {0, 4},  // Node 2 is connected to 0 and 4
        {1},     // Node 3 is connected to 1
        {2}      // Node 4 is connected to 2
    };

    cout << "BFS Traversal: ";
    bfs(graph, 0);
    return 0;
}

