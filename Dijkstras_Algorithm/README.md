### `README.md` for Dijkstra's Algorithm

---

# **Dijkstra's Algorithm**

This project implements **Dijkstra's Algorithm** in C++. Dijkstra's Algorithm is a greedy approach to find the shortest path from a source node to all other nodes in a weighted graph with non-negative edge weights.

---

## **Problem Description**

Given a weighted graph represented as an adjacency list, compute the shortest distances from a starting node to all other nodes.

### **Example Input**
```plaintext
Graph (Adjacency List):
Node 0: [(1, 2), (2, 4)]
Node 1: [(2, 1), (3, 7)]
Node 2: [(3, 3)]
Node 3: []

Start Node: 0
```

### **Expected Output**
```plaintext
Shortest distances from node 0:
Node 0: 0
Node 1: 2
Node 2: 3
Node 3: 6
```

---

## **How It Works**

1. **Initialization:**
   - Create a `dist` vector initialized to infinity (`INF`) for all nodes except the starting node (set to 0).
   - Use a priority queue (`pq`) to store nodes and their current shortest distances, prioritized by distance.

2. **Relax Edges:**
   - For the node with the smallest distance in the priority queue:
     - Visit all its neighbors.
     - If a shorter path to a neighbor is found, update its distance and push it into the priority queue.

3. **Output Results:**
   - After processing all nodes, the `dist` array contains the shortest distances from the start node to all other nodes.

---

## **Code Details**

### **Key Components**

1. **Graph Representation:**
   - The graph is represented as an adjacency list:
     ```cpp
     vector<vector<pair<int, int>>> graph;
     ```
     Each element is a list of pairs where `pair.first` is the neighbor and `pair.second` is the weight of the edge.

2. **Priority Queue:**
   - A min-heap (priority queue) is used to efficiently fetch the node with the smallest distance:
     ```cpp
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
     ```

3. **Dijkstra's Function:**
   - Implements the main logic of the algorithm, updating distances and relaxing edges.

4. **Main Function:**
   - Initializes the graph and calls the Dijkstra function with the starting node.

---

### **Code Walkthrough**

#### **Dijkstra's Function**
```cpp
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
```
- Initializes distances and the priority queue.
- Relaxes edges for each node and updates shortest distances.

#### **Main Function**
```cpp
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
```
- Defines the graph as an adjacency list.
- Calls the Dijkstra function with node `0` as the starting point.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `dijkstra.cpp`.
2. Compile the code:
   ```bash
   g++ dijkstra.cpp -o dijkstra
   ```
3. Run the program:
   ```bash
   ./dijkstra
   ```

---

## **Input/Output**

### **Input**
The program uses the following graph:
```plaintext
Graph (Adjacency List):
0 -> [(1, 2), (2, 4)]
1 -> [(2, 1), (3, 7)]
2 -> [(3, 3)]
3 -> []
```
Start node: `0`

### **Output**
The shortest distances from the start node:
```plaintext
Shortest distances from node 0:
Node 0: 0
Node 1: 2
Node 2: 3
Node 3: 6
```

---

## **Complexity**

### **Time Complexity**
- \(O((V + E) \log V)\):  
  - \(V\): Number of vertices.  
  - \(E\): Number of edges.  
  - Priority queue operations take \(O(\log V)\).

### **Space Complexity**
- \(O(V + E)\):  
  - Space for the adjacency list and distance array.

---

## **Applications**

1. **Network Routing:**
   - Finding the shortest path in network graphs (e.g., internet routing).

2. **Map Navigation:**
   - GPS systems use Dijkstra's algorithm to compute the shortest driving distance.

3. **Telecommunications:**
   - Efficiently finding the least-cost path for data transmission.

4. **AI Pathfinding:**
   - Game AI for shortest pathfinding.

---

## **Customization**

- Modify the adjacency list in the `main` function to test with different graphs.
- Change the `start` parameter in the `dijkstra` function to compute shortest distances from a different source.

---

This implementation of Dijkstra's Algorithm demonstrates how to compute shortest paths efficiently in weighted graphs using a priority queue. It is widely used in network routing, navigation systems, and optimization problems.