### `README.md` for Binary Search Algorithm

---

# **Binary Search Algorithm**

This project implements the **Binary Search Algorithm** in C++. Binary Search is an efficient algorithm for finding an element in a sorted array. It operates by repeatedly dividing the search interval in half until the target element is found or the interval is empty.

---

## **Problem Description**

Given a sorted array and a target value, determine the index of the target value in the array. If the target value does not exist, return \(-1\).

---

## **How It Works**

1. **Divide and Conquer Approach:**
   - Start with two pointers: `low` (beginning of the array) and `high` (end of the array).
   - Compute the midpoint of the current range:  
     \[
     \text{mid} = \text{low} + \frac{\text{high} - \text{low}}{2}
     \]
   - Compare the element at `mid` with the target:
     - If the element equals the target, return `mid`.
     - If the element is less than the target, search the right half of the array by moving `low` to `mid + 1`.
     - If the element is greater than the target, search the left half of the array by moving `high` to `mid - 1`.
   - Repeat until the target is found or the range becomes invalid.

2. **Output:**
   - If the target is found, return its index.
   - If the target is not found, return \(-1\).

---

## **Code Overview**

### **Binary Search Function**
```cpp
int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid; // Target found
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Target not found
}
```
- The function takes a **sorted array** (`arr`) and a **target value** as inputs.
- Uses a loop to repeatedly narrow down the search range.
- Returns the index of the target value if found, otherwise \(-1\).

### **Main Function**
```cpp
int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 30;
    int index = binarySearch(arr, target);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    return 0;
}
```
- Initializes a sorted array `arr` and defines the target value `30`.
- Calls `binarySearch()` and prints the result.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `binary_search.cpp`.
2. Compile the code:
   ```bash
   g++ binary_search.cpp -o binary_search
   ```
3. Run the program:
   ```bash
   ./binary_search
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded array and target value:
```cpp
vector<int> arr = {10, 20, 30, 40, 50};
int target = 30;
```

### **Output**
If the target is found:
```plaintext
Element found at index 2
```

If the target is not found:
```plaintext
Element not found!
```

---

## **Complexity**

### **Time Complexity**
- \(O(\log n)\): Each step reduces the search range by half, resulting in a logarithmic time complexity.

### **Space Complexity**
- \(O(1)\): Uses constant additional space.

---

## **Applications**

1. **Searching in Sorted Arrays:**
   - Quickly locate elements in large datasets.

2. **Competitive Programming:**
   - Commonly used in problems involving searching in sorted lists.

3. **Real-World Scenarios:**
   - Searching for records in databases.
   - Efficiently locating items in inventory systems.

---

## **Customization**

- Modify the `arr` variable in the `main()` function to test with different datasets.
- Change the `target` variable to search for different elements.

---

This implementation of Binary Search provides an efficient and reliable method for finding elements in sorted arrays, leveraging the power of divide-and-conquer.