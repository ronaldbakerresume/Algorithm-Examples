### `README.md` for Bellman-Ford Algorithm

---

# **Bellman-Ford Algorithm**

This project implements the **Bellman-Ford Algorithm** in C++ to compute the shortest paths from a single source vertex to all other vertices in a weighted graph. It is capable of handling graphs with negative-weight edges and detects negative-weight cycles.

---

## **Problem Description**

Given a graph with \(V\) vertices and \(E\) edges, the Bellman-Ford algorithm calculates the shortest path from a source vertex to all other vertices. Unlike Dijkstra's algorithm, it works correctly for graphs with negative-weight edges.

### **Example Graph**
```plaintext
Edges: [
    (0 -> 1, weight = -1),
    (0 -> 2, weight = 4),
    (1 -> 2, weight = 3),
    (1 -> 3, weight = 2),
    (1 -> 4, weight = 2),
    (3 -> 2, weight = 5),
    (3 -> 1, weight = 1),
    (4 -> 3, weight = -3)
]
```

### **Expected Output**
```plaintext
Vertex   Distance from Source
0        0
1        -1
2        2
3        -2
4        1
```

---

## **How It Works**

### **Algorithm Steps**

1. **Initialization:**
   - Set the distance to the source vertex as 0 and all other vertices as \(+\infty\).

2. **Relaxation:**
   - For each edge in the graph, update the distance to the destination vertex if the current path is shorter.

3. **Cycle Detection:**
   - After \(V-1\) iterations, perform one more iteration. If any edge can still be relaxed, the graph contains a negative-weight cycle.

---

## **Code Overview**

### **Key Components**
1. **Struct Definition:**  
   The `Edge` struct represents an edge in the graph with `src`, `dest`, and `weight`.

2. **Main Logic:**  
   The `bellmanFord` function implements the algorithm to compute shortest paths and detect negative-weight cycles.

---

### **Code Walkthrough**

#### **Struct Definition**
```cpp
struct Edge {
    int src, dest, weight;
};
```
The `Edge` struct models a directed edge in the graph.

#### **Relaxation**
```cpp
for (int i = 1; i < V; ++i) {
    for (const auto& edge : edges) {
        if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
            dist[edge.dest] = dist[edge.src] + edge.weight;
        }
    }
}
```
This loop relaxes each edge \(V-1\) times to compute the shortest paths.

#### **Negative-Weight Cycle Detection**
```cpp
for (const auto& edge : edges) {
    if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
        cout << "Graph contains a negative-weight cycle!" << endl;
        return;
    }
}
```
An additional iteration checks if any edge can still be relaxed, indicating a negative-weight cycle.

#### **Output**
```cpp
for (int i = 0; i < V; ++i) {
    cout << i << " \t" << dist[i] << endl;
}
```
This prints the shortest distances from the source vertex to all other vertices.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `bellman_ford.cpp`.
2. Compile the code:
   ```bash
   g++ bellman_ford.cpp -o bellman_ford
   ```
3. Run the program:
   ```bash
   ./bellman_ford
   ```

---

## **Input/Output**

### **Input**
The program uses a hardcoded list of edges and the number of vertices:
```cpp
vector<Edge> edges = {
    {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
    {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
int V = 5;
```

### **Output**
The program outputs the shortest distance from the source vertex to all other vertices:
```plaintext
Vertex   Distance from Source
0        0
1        -1
2        2
3        -2
4        1
```

If a negative-weight cycle exists:
```plaintext
Graph contains a negative-weight cycle!
```

---

## **Complexity**

### **Time Complexity**
- **Relaxation:** \(O(V \times E)\)
- **Cycle Detection:** \(O(E)\)  
**Total:** \(O(V \times E)\)

### **Space Complexity**
- \(O(V)\) for the distance array.

---

## **Customization**

- Modify the `edges` vector to represent different graphs.
- Change the `start` parameter in the `bellmanFord` function to use a different source vertex.

---

## **Applications**

- Shortest path in graphs with negative weights.
- Currency arbitrage detection in financial systems.
- Routing in computer networks.

---

This implementation serves as an efficient method for solving the single-source shortest path problem in graphs with negative-weight edges.