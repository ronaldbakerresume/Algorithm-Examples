#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int V, vector<Edge>& edges, int start) {
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;

    for (int i = 1; i < V; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    for (const auto& edge : edges) {
        if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
            cout << "Graph contains a negative-weight cycle!" << endl;
            return;
        }
    }

    cout << "Vertex \tDistance from Source\n";
    for (int i = 0; i < V; ++i) {
        cout << i << " \t" << dist[i] << endl;
    }
}

int main() {
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    int V = 5; // Number of vertices
    bellmanFord(V, edges, 0);

    return 0;
}

