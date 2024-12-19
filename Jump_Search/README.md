### `README.md` for Jump Search Implementation

---

# **Jump Search**

This project implements the **Jump Search** algorithm in C++. Jump Search is an efficient searching algorithm for sorted arrays. It works by jumping ahead by fixed steps and then performing a linear search within the identified block.

---

## **Problem Description**

Given a sorted array and a target value, the goal is to find the index of the target in the array using Jump Search. If the target is not found, return `-1`.

### **Example Input**

```plaintext
Array: [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
Target: 21
```

### **Expected Output**

```plaintext
Element found at index 8
```

---

## **How It Works**

### **Jump Search Steps**

1. **Step Size:**
   - Compute the step size as the square root of the array size:
     \[
     \text{step} = \sqrt{n}
     \]

2. **Jump Forward:**
   - Jump forward by `step` indices until the element at the current position is greater than or equal to the target or the end of the array is reached.

3. **Linear Search:**
   - Perform a linear search within the block identified in the previous step.

4. **Return Index:**
   - If the target is found, return its index; otherwise, return `-1`.

---

## **Code Details**

### **Key Components**

1. **Jump Search Function:**
   - Implements the Jump Search algorithm:
     ```cpp
     int jumpSearch(const vector<int>& arr, int target) {
         int n = arr.size();
         int step = sqrt(n);
         int prev = 0;

         while (arr[min(step, n) - 1] < target) {
             prev = step;
             step += sqrt(n);
             if (prev >= n) return -1;
         }

         for (int i = prev; i < min(step, n); ++i) {
             if (arr[i] == target) return i;
         }

         return -1;
     }
     ```

   - The loop ensures the search range is reduced efficiently by jumping `step` elements.
   - A linear search is performed only within the identified block.

2. **Main Function:**
   - Defines the input array and target value, and calls the `jumpSearch` function:
     ```cpp
     int main() {
         vector<int> arr = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
         int target = 21;
         int index = jumpSearch(arr, target);
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
1. Copy the code into a file named `jump_search.cpp`.
2. Compile the code:
   ```bash
   g++ jump_search.cpp -o jump_search -lm
   ```
3. Run the program:
   ```bash
   ./jump_search
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded array and target:
```plaintext
Array: [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
Target: 21
```

### **Output**
The program outputs:
```plaintext
Element found at index 8
```

---

## **Complexity**

### **Time Complexity**
- **Best Case:** \(O(1)\):  
  - If the target is found at the first jump.
- **Worst Case:** \(O(\sqrt{n})\):  
  - If the target is in the last block or not in the array.
- **Average Case:** \(O(\sqrt{n})\)

### **Space Complexity**
- \(O(1)\):  
  - No additional data structures are used.

---

## **Applications**

1. **Sorted Datasets:**
   - Ideal for searching in sorted arrays, such as database indices or lookup tables.

2. **Performance Improvement:**
   - Faster than linear search for large datasets.

---

## **Customization**

- Modify the `arr` and `target` in the `main()` function to test with different datasets.
- Adjust the step size calculation for specific performance optimizations.

---

## **Advantages**

- Faster than linear search for sorted arrays.
- Simple and easy to implement.

---

## **Limitations**

- Requires the input array to be sorted.
- Not as efficient as binary search for most cases.

---

This implementation of Jump Search demonstrates its utility as a straightforward and efficient search algorithm for sorted datasets.