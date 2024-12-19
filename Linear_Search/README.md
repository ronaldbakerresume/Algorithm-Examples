### `README.md` for Linear Search Implementation

---

# **Linear Search**

This project implements **Linear Search** in C++. Linear Search is a simple algorithm to find the position of a target element in an array or vector by checking each element sequentially.

---

## **Problem Description**

Given:
- An array or vector of elements.
- A target value to search for.

Goal:
- Find the index of the target value in the array or return \(-1\) if the target is not found.

### **Example Input**

```plaintext
Array: [10, 20, 30, 40, 50]
Target: 30
```

### **Expected Output**

```plaintext
Element found at index 2
```

---

## **How It Works**

### **Algorithm**

1. Start at the first element of the array.
2. Compare each element with the target value.
3. If a match is found, return the index of the element.
4. If the end of the array is reached without finding the target, return \(-1\).

---

## **Code Details**

### **Key Components**

1. **Linear Search Function:**
   - Traverses the array to find the target:
     ```cpp
     int linearSearch(const vector<int>& arr, int target) {
         for (int i = 0; i < arr.size(); ++i) {
             if (arr[i] == target) return i; // Return index of the target
         }
         return -1; // Return -1 if not found
     }
     ```

2. **Main Function:**
   - Defines the input array and target value, and calls the `linearSearch` function:
     ```cpp
     int main() {
         vector<int> arr = {10, 20, 30, 40, 50};
         int target = 30;
         int index = linearSearch(arr, target);
         if (index != -1) {
             cout << "Element found at index " << index << endl;
         } else {
             cout << "Element not found!" << endl;
         }
         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `linear_search.cpp`.
2. Compile the code:
   ```bash
   g++ linear_search.cpp -o linear_search
   ```
3. Run the program:
   ```bash
   ./linear_search
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded values:
```plaintext
Array: [10, 20, 30, 40, 50]
Target: 30
```

### **Output**
```plaintext
Element found at index 2
```

---

## **Complexity**

### **Time Complexity**
- **Best Case:** \(O(1)\) (Target is the first element).
- **Worst Case:** \(O(n)\) (Target is the last element or not present).

### **Space Complexity**
- \(O(1)\): No extra space is used.

---

## **Applications**

1. **Unordered Data:**
   - Suitable for arrays or lists that are not sorted.
2. **Small Data Sets:**
   - Efficient for small arrays where the overhead of more complex algorithms is unnecessary.
3. **Debugging:**
   - Useful for basic validation and troubleshooting.

---

## **Customization**

- Modify the `arr` and `target` variables in the `main()` function to test with different inputs.
- Extend the function to return all indices if the target value appears multiple times.

---

## **Advantages**

1. Simple and easy to implement.
2. Does not require the array to be sorted.
3. Works well for small datasets.

---

## **Limitations**

1. Inefficient for large arrays due to \(O(n)\) time complexity.
2. Requires checking every element, even if the target is near the end.

---

This implementation of Linear Search is a straightforward solution for searching in unsorted datasets, providing a foundation for understanding more advanced search algorithms.