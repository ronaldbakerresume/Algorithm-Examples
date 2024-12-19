### `README.md` for Floyd-Warshall Algorithm

---

# **Floyd-Warshall Algorithm**

This project implements the **Floyd-Warshall Algorithm** in C++. The algorithm computes the shortest paths between all pairs of vertices in a weighted graph. It can handle both directed and undirected graphs and works with graphs containing positive or negative edge weights, provided there are no negative weight cycles.

---

## **Problem Description**

Given a graph represented as an adjacency matrix, compute the shortest distances between every pair of vertices. If a path between two vertices does not exist, represent the distance as `INF` (infinity).

---

### **Example Input**

```plaintext
Graph (Adjacency Matrix):
[ 0   3   INF INF ]
[ 2   0   INF INF ]
[ INF 7   0   1   ]
[ 6   INF INF 0   ]
```

### **Expected Output**

```plaintext
Shortest distances between every pair of vertices:
[ 0   3   INF  INF  ]
[ 2   0   INF  INF  ]
[ INF 7   0    1    ]
[ 6   9    10   0   ]
```

---

## **How It Works**

### **Key Concept**

The Floyd-Warshall Algorithm updates the shortest path between any two vertices in a graph iteratively. It considers each vertex as an intermediate point between pairs of vertices to check if a shorter path exists.

### **Steps**

1. **Initialization:**
   - Start with the input graph as the initial distances. Each cell in the adjacency matrix represents the direct distance between two vertices, or `INF` if no direct edge exists.

2. **Iterative Updates:**
   - For each vertex \(k\), consider it as an intermediate point.
   - For every pair of vertices \(i\) and \(j\):
     - Update the distance using:
       \[
       \text{dist}[i][j] = \min(\text{dist}[i][j], \text{dist}[i][k] + \text{dist}[k][j])
       \]

3. **Final Matrix:**
   - After all iterations, the matrix contains the shortest distances between every pair of vertices.

---

## **Code Details**

### **Key Components**

1. **Adjacency Matrix:**
   - The graph is represented as a 2D vector where `graph[i][j]` stores the weight of the edge from vertex \(i\) to vertex \(j\).

2. **Distance Matrix:**
   - A copy of the graph is made to iteratively compute the shortest distances.

3. **Core Algorithm:**
   - Three nested loops:
     - The outer loop iterates over each vertex \(k\) as an intermediate.
     - The two inner loops iterate over all pairs of vertices \((i, j)\) to update their shortest distance.

---

### **Code Walkthrough**

#### **Floyd-Warshall Function**

```cpp
void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
```

- **Initialization:**
  - The `dist` matrix is initialized with the same values as the input graph.
- **Triple Nested Loops:**
  - \(k\) is the intermediate vertex.
  - \(i, j\) are the pair of vertices being updated.
- **Matrix Update Rule:**
  - If a shorter path exists via \(k\), update `dist[i][j]`.

---

#### **Main Function**

```cpp
int main() {
    vector<vector<int>> graph = {
        {0, 3, INT_MAX, INT_MAX},
        {2, 0, INT_MAX, INT_MAX},
        {INT_MAX, 7, 0, 1},
        {6, INT_MAX, INT_MAX, 0}};

    floydWarshall(graph);
    return 0;
}
```

- Defines the input graph as an adjacency matrix.
- Calls the `floydWarshall` function to compute the shortest paths.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `floyd_warshall.cpp`.
2. Compile the code:
   ```bash
   g++ floyd_warshall.cpp -o floyd_warshall
   ```
3. Run the program:
   ```bash
   ./floyd_warshall
   ```

---

## **Input/Output**

### **Input**
The program uses the following graph as input:
```plaintext
[ 0   3   INF INF ]
[ 2   0   INF INF ]
[ INF 7   0   1   ]
[ 6   INF INF 0   ]
```

### **Output**
The shortest distances between every pair of vertices:
```plaintext
Shortest distances between every pair of vertices:
0 3 INF INF
2 0 INF INF
INF 7 0 1
6 9 10 0
```

---

## **Complexity**

### **Time Complexity**
- \(O(V^3)\):  
  - Three nested loops iterate over all vertices.

### **Space Complexity**
- \(O(V^2)\):  
  - Additional space for the distance matrix.

---

## **Applications**

1. **Network Routing:**
   - Computes shortest paths between all pairs of nodes in a network.

2. **Urban Traffic Analysis:**
   - Finds the shortest paths between intersections in city road networks.

3. **Game Development:**
   - Pathfinding in grids or graphs where all-pairs shortest paths are required.

4. **Social Network Analysis:**
   - Measures closeness or connectivity between entities.

---

## **Customization**

- Modify the `graph` adjacency matrix in the `main()` function to test different graphs.
- Handle negative weight cycles by adding a check:
  - If `dist[i][i] < 0` after the algorithm, the graph contains a negative weight cycle.

---

This implementation of the Floyd-Warshall Algorithm efficiently computes all-pairs shortest paths, demonstrating its utility in solving graph problems in various domains.