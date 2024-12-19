### `README.md` for Union-Find Implementation

---

# **Union-Find (Disjoint Set Union)**

This project demonstrates the implementation of the **Union-Find** data structure, also known as **Disjoint Set Union (DSU)**. The Union-Find structure is widely used in various algorithms, including those for graph connectivity and clustering.

---

## **Overview**

The Union-Find data structure is designed to efficiently solve the dynamic connectivity problem:
1. **Find Operation:** Determine which subset (or set representative) a particular element belongs to.
2. **Union Operation:** Merge two subsets into a single subset.

Optimizations like **Path Compression** and **Union by Rank** improve performance, achieving nearly constant time complexity per operation, expressed as \(O(\alpha(n))\), where \(\alpha(n)\) is the inverse Ackermann function.

---

## **Key Features**
- **Dynamic Connectivity:** Connect two nodes or query if two nodes are in the same connected component.
- **Efficient Operations:** Optimized with path compression and union by rank.
- **Simple API:** `find` and `unionSets` operations.

---

## **Code Details**

### **Class: UnionFind**

#### **Constructor**
```cpp
UnionFind(int size);
```
- Initializes a Union-Find structure for `size` elements.

#### **Methods**

1. **`int find(int x)`**
   - Finds the representative (root) of the set containing element `x`.
   - **Path Compression** ensures the tree structure is flattened for faster future queries.

2. **`void unionSets(int x, int y)`**
   - Merges the sets containing elements `x` and `y`.
   - **Union by Rank** ensures the smaller tree is attached under the larger tree, maintaining a balanced structure.

---

## **Example**

### **Input**
The following operations are performed:
1. Union of sets containing `1` and `2`.
2. Union of sets containing `2` and `3`.
3. Find the representative of the set containing `1`.
4. Find the representative of the set containing `3`.

### **Code**
```cpp
UnionFind uf(10);
uf.unionSets(1, 2);
uf.unionSets(2, 3);
cout << "Find(1): " << uf.find(1) << endl; // Output: 1 or 2
cout << "Find(3): " << uf.find(3) << endl; // Output: Same as Find(1)
```

### **Output**
```plaintext
Find(1): 1
Find(3): 1
```

---

## **Time Complexity**
- **Find Operation:** \(O(\alpha(n))\) (with path compression).
- **Union Operation:** \(O(\alpha(n))\) (with union by rank).
- **Overall Complexity:** Nearly \(O(1)\) per operation for practical purposes.

---

## **Applications**
1. **Graph Algorithms:**
   - **Kruskal's Algorithm** for finding the Minimum Spanning Tree (MST).
   - Detecting **cycle** in undirected graphs.
2. **Clustering:**
   - Grouping similar items.
3. **Network Connectivity:**
   - Checking if two nodes are in the same connected component.
4. **Dynamic Equivalence:**
   - Problems involving equivalence classes.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`).

### **Steps**
1. Save the code to a file named `union_find.cpp`.
2. Compile the code:
   ```bash
   g++ union_find.cpp -o union_find
   ```
3. Run the program:
   ```bash
   ./union_find
   ```

---

## **Advantages**
1. Highly efficient for a large number of dynamic connectivity queries.
2. Flexible and simple to use.

---

## **Enhancements**
- Implement weighted union for further optimization.
- Extend to support additional operations like keeping track of subset sizes.

---