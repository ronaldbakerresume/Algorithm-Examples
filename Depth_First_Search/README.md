### `README.md` for Depth-First Search (DFS) Algorithm

---

# **Depth-First Search (DFS) Algorithm**

This project implements the **Depth-First Search (DFS)** algorithm in C++. DFS is a fundamental graph traversal technique used to explore nodes and edges in a graph by visiting as deep as possible along each branch before backtracking.

---

## **Problem Description**

Given a graph represented as an adjacency list, the task is to traverse the graph using DFS starting from a specified node and print the order of visited nodes.

---

## **How It Works**

1. **Start from the Source Node:**
   - Mark the source node as visited and print it.
   - Recursively visit its unvisited neighbors.

2. **Backtracking:**
   - When all neighbors of a node have been visited, backtrack to explore other unexplored branches.

3. **Output:**
   - Print the order in which nodes are visited during the DFS traversal.

---

## **Code Details**

### **Key Components**

1. **Recursive DFS Helper Function:**
   - Recursively explores nodes starting from a given node.

2. **Visited Array:**
   - Tracks whether a node has already been visited to prevent cycles.

3. **Main DFS Function:**
   - Initializes the `visited` array and calls the recursive helper.

4. **Main Function:**
   - Defines the graph and starts the DFS traversal from a specified node.

---

### **Code Walkthrough**

#### **DFS Helper Function**
```cpp
void dfsHelper(const vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsHelper(graph, neighbor, visited);
        }
    }
}
```
- Marks the current node as visited and prints it.
- Recursively visits all unvisited neighbors.

#### **DFS Function**
```cpp
void dfs(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    dfsHelper(graph, start, visited);
}
```
- Initializes a `visited` array of size equal to the number of nodes in the graph.
- Calls the recursive `dfsHelper` function with the starting node.

#### **Main Function**
```cpp
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
```
- Defines the graph using an adjacency list.
- Starts the DFS traversal from node `0`.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `dfs.cpp`.
2. Compile the code:
   ```bash
   g++ dfs.cpp -o dfs
   ```
3. Run the program:
   ```bash
   ./dfs
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded graph:
```plaintext
Graph (Adjacency List):
0 -> [1, 2]
1 -> [0, 3]
2 -> [0, 4]
3 -> [1]
4 -> [2]
```

### **Output**
The DFS traversal starting from node `0`:
```plaintext
DFS Traversal: 0 1 3 2 4
```

---

## **Complexity**

### **Time Complexity**
- \(O(V + E)\):  
  - \(V\): Number of vertices.  
  - \(E\): Number of edges.  
  - Each node and edge is visited once.

### **Space Complexity**
- \(O(V)\):  
  - Space for the `visited` array and the recursion stack.

---

## **Applications**

1. **Graph Traversal:**
   - Used in solving connectivity problems and exploring all nodes of a graph.

2. **Cycle Detection:**
   - DFS can detect cycles in a graph.

3. **Topological Sorting:**
   - DFS is used to compute the topological order of nodes in a Directed Acyclic Graph (DAG).

4. **Maze and Puzzle Solving:**
   - DFS is useful in exploring possible paths in mazes or puzzles.

5. **Connected Components:**
   - Identify connected components in an undirected graph.

---

## **Customization**

- Modify the adjacency list in the `main()` function to test different graph structures.
- Change the `start` parameter in the `dfs()` function to begin traversal from a different node.

---

This implementation of Depth-First Search (DFS) is a simple yet powerful example of a recursive graph traversal technique, widely used in both academic and real-world applications.