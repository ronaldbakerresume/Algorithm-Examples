### `README.md` for Segment Tree Implementation

---

# **Segment Tree Implementation**

This project implements a **Segment Tree** for efficient range queries and updates on an array. Segment Trees are particularly useful in scenarios where frequent updates and queries are performed on data.

---

## **Overview**

A **Segment Tree** is a binary tree structure where each node represents a segment (range) of an array. It supports:
1. **Range Queries:** Compute a function (e.g., sum, min, max) over a subarray.
2. **Point Updates:** Update an element in the array and propagate the changes efficiently.

---

## **Key Features**
1. **Construction:**
   - The tree is built recursively, dividing the array into smaller ranges.
2. **Range Queries:**
   - Query operations are performed in \(O(\log n)\) by combining results from the relevant segments.
3. **Point Updates:**
   - Update operations modify a specific element and update its corresponding segments in \(O(\log n)\).

---

## **Code Details**

### **Classes and Methods**

#### **Class: `SegmentTree`**
- **Private Members:**
  - `vector<int> tree, arr`: The segment tree array and the input array.
  - `int n`: Size of the input array.
  - **`buildTree(int node, int start, int end):`**
    Recursively builds the tree, storing the sum of ranges.
  - **`queryTree(int node, int start, int end, int L, int R):`**
    Recursively queries the tree for a given range.
  - **`updateTree(int node, int start, int end, int index, int value):`**
    Updates the value at a specific index and propagates changes.

- **Public Methods:**
  - **`SegmentTree(vector<int>& input):`**
    Constructor to initialize the tree and build it.
  - **`query(int L, int R):`**
    Returns the sum of elements in the range \([L, R]\).
  - **`update(int index, int value):`**
    Updates the value at `index` and modifies the tree.

---

## **Algorithm**

### **Tree Construction**
- Start by dividing the array into halves.
- Recursively compute and store the sum of the left and right halves in the tree nodes.

### **Range Query**
- Check if the current segment lies entirely within, partially within, or completely outside the query range.
- Combine results from relevant segments.

### **Point Update**
- Locate the leaf node corresponding to the index and update its value.
- Recursively update the parent nodes to reflect the changes.

---

## **Code Example**

### **Initialization**
```cpp
vector<int> arr = {1, 3, 5, 7, 9, 11};
SegmentTree segTree(arr);
```

### **Range Query**
```cpp
cout << "Sum of range [1, 3]: " << segTree.query(1, 3) << endl;
```

### **Point Update**
```cpp
segTree.update(1, 10); // Update index 1 to 10
cout << "Sum of range [1, 3] after update: " << segTree.query(1, 3) << endl;
```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`).

### **Steps**
1. Save the code to a file named `segment_tree.cpp`.
2. Compile the code:
   ```bash
   g++ segment_tree.cpp -o segment_tree
   ```
3. Run the program:
   ```bash
   ./segment_tree
   ```

---

## **Input/Output**

### **Input**
- Array: \([1, 3, 5, 7, 9, 11]\)
- Operations:
  - Query sum of range \([1, 3]\).
  - Update index \(1\) to \(10\).
  - Query sum of range \([1, 3]\) after update.

### **Output**
```plaintext
Sum of range [1, 3]: 15
Sum of range [1, 3] after update: 22
```

---

## **Time Complexity**
- **Construction:** \(O(n)\)
- **Range Query:** \(O(\log n)\)
- **Point Update:** \(O(\log n)\)

---

## **Applications**
1. **Range Queries:**
   - Prefix sums, range sums, and range minimum/maximum queries.
2. **Dynamic Updates:**
   - Handle changes in data without rebuilding the structure.
3. **Efficient Computations:**
   - Solve problems involving cumulative operations over subarrays.

---

## **Advantages**
- Efficient for dynamic array queries and updates.
- Reduces time complexity compared to naive methods.

---

## **Enhancements**
- Extend functionality for different operations (e.g., range minimum query).
- Implement lazy propagation for range updates.