### `README.md` for Fenwick Tree (Binary Indexed Tree)

---

# **Fenwick Tree (Binary Indexed Tree)**

This project implements a **Fenwick Tree** (also known as a Binary Indexed Tree) in C++. Fenwick Trees are efficient data structures for performing prefix sum queries and updates in logarithmic time.

---

## **Overview**

A Fenwick Tree is a data structure that allows efficient computation of cumulative frequencies or sums. It is widely used in scenarios where there are frequent updates to an array and queries for cumulative sums.

### **Supported Operations**
1. **Point Update:** Update the value at a specific index.
2. **Prefix Sum Query:** Compute the cumulative sum from the start of the array to a given index.
3. **Range Sum Query:** Compute the sum of values in a specific range.

---

## **Code Details**

### **Key Components**
1. **Data Structure:**
   - A `vector<int>` named `bit` (Binary Indexed Tree) is used to store the Fenwick Tree.
   - The size of the tree is determined by the size of the input array.

2. **Core Methods:**
   - **`update(index, value)`**: Updates the value at a specific index in logarithmic time.
   - **`query(index)`**: Computes the prefix sum up to a given index in logarithmic time.
   - **`rangeQuery(left, right)`**: Computes the sum of values in a given range `[left, right]` by subtracting prefix sums.

---

### **Code Walkthrough**

#### **Initialization**
```cpp
FenwickTree(int n) {
    size = n + 1;
    bit.assign(size, 0);
}
```
The constructor initializes the `bit` array of size \(n+1\) to store the tree. The size is \(n+1\) because Fenwick Tree is 1-indexed.

#### **Point Update**
```cpp
void update(int index, int value) {
    for (; index < size; index += index & -index) {
        bit[index] += value;
    }
}
```
This function updates the Fenwick Tree with a given value at a specified index by traversing up the tree using the **least significant bit** (LSB).

#### **Prefix Sum Query**
```cpp
int query(int index) {
    int sum = 0;
    for (; index > 0; index -= index & -index) {
        sum += bit[index];
    }
    return sum;
}
```
This function calculates the prefix sum from the start of the array to the given index by traversing down the tree.

#### **Range Sum Query**
```cpp
int rangeQuery(int left, int right) {
    return query(right) - query(left - 1);
}
```
This function calculates the sum of values in the range `[left, right]` by combining two prefix sum queries.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `fenwick_tree.cpp`.
2. Compile the code:
   ```bash
   g++ fenwick_tree.cpp -o fenwick_tree
   ```
3. Run the program:
   ```bash
   ./fenwick_tree
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded updates:
```cpp
fenwick.update(1, 5);  // Add 5 at index 1
fenwick.update(4, 7);  // Add 7 at index 4
fenwick.update(7, 3);  // Add 3 at index 7
```

### **Output**
The program performs range queries and outputs:
```plaintext
Sum of range [1, 4]: 12
Sum of range [1, 7]: 15
```

---

## **Complexity**

### **Time Complexity**
- **Point Update:** \(O(\log n)\)
- **Prefix Sum Query:** \(O(\log n)\)
- **Range Query:** \(O(\log n)\)

### **Space Complexity**
- \(O(n)\) for the `bit` array.

---

## **Applications**

1. **Cumulative Frequency Tables:**
   - Counting occurrences of elements in ranges.

2. **Dynamic Array Summation:**
   - Frequently updating values in an array while maintaining efficient range sum queries.

3. **Inversions in Arrays:**
   - Counting inversions in an array in \(O(n \log n)\).

4. **Competitive Programming:**
   - Problems involving dynamic range queries and updates.

---

## **Customization**

- Modify the size of the Fenwick Tree in the `main()` function to handle larger arrays.
- Use the `rangeQuery()` method for more complex range operations.

---

This implementation provides an efficient and compact way to handle cumulative sums and dynamic updates in logarithmic time, making it a great fit for competitive programming and real-world applications.