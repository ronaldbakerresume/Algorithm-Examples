### `README.md` for Prim's Minimum Spanning Tree (MST) Algorithm

---

# **Prim's Minimum Spanning Tree (MST) Algorithm**

This project demonstrates the implementation of **Prim's Algorithm** in C++ to find the Minimum Spanning Tree (MST) of a weighted undirected graph.

---

## **Problem Description**

Given:
- A weighted, connected, undirected graph.

Goal:
- Find a subset of edges that forms a tree including all vertices such that:
  - The total weight of the edges in the tree is minimized.
  - There are no cycles in the tree.

---

## **Algorithm**

Prim's Algorithm grows the MST starting from an arbitrary vertex and adds the minimum weight edge that connects a new vertex to the tree in each step.

### **Steps**

1. **Initialization:**
   - Maintain a `key` array to store the minimum weight edge connecting a vertex to the tree.
   - Use a `parent` array to store the MST.
   - Use a `visited` array (`inMST`) to track vertices already included in the MST.

2. **Greedy Selection:**
   - Start with any vertex (e.g., vertex `0`).
   - At each step, pick the vertex with the smallest `key` value that is not already in the MST.

3. **Update:**
   - Update the `key` and `parent` values for vertices adjacent to the selected vertex.

4. **Repeat:**
   - Repeat until all vertices are included in the MST.

---

## **Code Details**

### **Key Components**

1. **Find Minimum Vertex Function:**
   - Finds the vertex with the smallest key value that is not yet in the MST:
     ```cpp
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
     ```

2. **Prim's Algorithm:**
   - Constructs the MST and prints the edges and their weights:
     ```cpp
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
     ```

3. **Main Function:**
   - Defines the graph and calls the `primsMST` function:
     ```cpp
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
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`).

### **Steps**
1. Copy the code into a file named `prims_mst.cpp`.
2. Compile the code:
   ```bash
   g++ prims_mst.cpp -o prims_mst
   ```
3. Run the program:
   ```bash
   ./prims_mst
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded adjacency matrix to represent the graph:
```plaintext
Graph:
    0 --2-- 1
    |      /|\
    6     3 | 5
    |  /--- 2
    3
```

### **Output**
```plaintext
Edge    Weight
0 - 1   2
1 - 2   3
0 - 3   6
1 - 4   5
```

---

## **Complexity**

### **Time Complexity**
- \(O(V^2)\): For the adjacency matrix representation.

### **Space Complexity**
- \(O(V)\): For `key`, `parent`, and `inMST` arrays.

---

## **Applications**

1. **Network Design:**
   - Designing minimum-cost networks (e.g., roadways, pipelines, communication networks).
2. **Computer Graphics:**
   - Constructing meshes for 3D models.
3. **Circuit Design:**
   - Connecting components with minimum wiring.

---

## **Limitations**

1. **Dense Graphs:**
   - Efficient for dense graphs. Use a priority queue for sparse graphs to reduce complexity to \(O(E \log V)\).
2. **Disconnected Graphs:**
   - Only works for connected graphs.

---

This implementation of Prim's Algorithm demonstrates an efficient method for solving MST problems in weighted, undirected graphs.