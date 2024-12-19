#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

void dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    vector<int> dist(graph.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (currDist > dist[node]) continue;

        for (auto& edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < dist.size(); ++i) {
        cout << "Node " << i << ": " << dist[i] << endl;
    }
}

int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1, 2}, {2, 4}},  // Node 0 -> 1 (weight 2), 0 -> 2 (weight 4)
        {{2, 1}, {3, 7}},  // Node 1 -> 2 (weight 1), 1 -> 3 (weight 7)
        {{3, 3}},          // Node 2 -> 3 (weight 3)
        {}                 // Node 3 has no outgoing edges
    };

    dijkstra(graph, 0);
    return 0;
}

