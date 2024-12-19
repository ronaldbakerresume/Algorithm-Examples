### `README.md` for Breadth-First Search (BFS) Algorithm

---

# **Breadth-First Search (BFS) Algorithm**

This project implements the **Breadth-First Search (BFS)** algorithm in C++. BFS is a fundamental graph traversal technique that explores all the vertices of a graph layer by layer starting from a given source node.

---

## **Problem Description**

Given an undirected or directed graph represented as an adjacency list, the task is to traverse the graph using the BFS algorithm starting from a specified node and print the order of visited nodes.

---

## **How It Works**

1. **Start from the Source Node:**
   - Push the source node into a queue and mark it as visited.

2. **Explore Neighbors:**
   - While the queue is not empty:
     - Pop a node from the queue.
     - Visit all its unvisited neighbors and add them to the queue.
     - Mark each visited neighbor to avoid revisiting.

3. **Output:**
   - Print the order in which the nodes are visited.

---

## **Code Details**

### **Key Components**

1. **Graph Representation:**
   - The graph is represented as an adjacency list using a `vector<vector<int>>`.

2. **BFS Function:**
   - Performs the BFS traversal using a queue and a `visited` vector.

3. **Main Function:**
   - Defines the graph and calls the BFS function starting from a specified node.

---

### **Code Walkthrough**

#### **BFS Function**
```cpp
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
```
- Initializes a `visited` vector to track visited nodes.
- Uses a queue to store nodes for exploration.
- Iteratively explores and visits unvisited neighbors of each node.

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

    cout << "BFS Traversal: ";
    bfs(graph, 0);
    return 0;
}
```
- Represents the graph as an adjacency list.
- Calls `bfs()` starting from node 0.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `bfs.cpp`.
2. Compile the code:
   ```bash
   g++ bfs.cpp -o bfs
   ```
3. Run the program:
   ```bash
   ./bfs
   ```

---

## **Input/Output**

### **Input**
The program uses a hardcoded adjacency list to represent the graph:
```cpp
vector<vector<int>> graph = {
    {1, 2},  // Node 0 is connected to 1 and 2
    {0, 3},  // Node 1 is connected to 0 and 3
    {0, 4},  // Node 2 is connected to 0 and 4
    {1},     // Node 3 is connected to 1
    {2}      // Node 4 is connected to 2
};
```

### **Output**
The BFS traversal order starting from node 0:
```plaintext
BFS Traversal: 0 1 2 3 4
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
  - Space for the `visited` vector and the queue.

---

## **Applications**

1. **Shortest Path in Unweighted Graphs:**
   - BFS can find the shortest path between two nodes in an unweighted graph.

2. **Web Crawlers:**
   - BFS is used to traverse linked pages on the internet.

3. **Network Analysis:**
   - BFS is employed to explore connections in a network.

4. **Solving Puzzles:**
   - BFS can be used in solving puzzles like mazes and shortest path problems.

---

## **Customization**

- Change the adjacency list to represent a different graph structure.
- Modify the `start` parameter in the `bfs()` function to begin traversal from a different node.

---

This implementation provides an efficient method to explore graphs layer by layer, making it suitable for a wide variety of real-world applications.