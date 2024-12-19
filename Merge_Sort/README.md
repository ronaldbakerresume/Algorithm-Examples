### `README.md` for Merge Sort Implementation

---

# **Merge Sort**

This project implements **Merge Sort** in C++. Merge Sort is a classic **Divide and Conquer** algorithm for sorting an array with a guaranteed time complexity of \(O(n \log n)\).

---

## **Problem Description**

Given:
- An unsorted array of integers.

Goal:
- Sort the array in ascending order using the Merge Sort algorithm.

### **Example Input**

```plaintext
Input: [12, 11, 13, 5, 6, 7]
```

### **Expected Output**

```plaintext
Output: [5, 6, 7, 11, 12, 13]
```

---

## **How It Works**

### **Algorithm**

1. **Divide:**
   - Recursively split the array into two halves until each subarray contains a single element.

2. **Conquer:**
   - Merge the subarrays back together in sorted order.

3. **Combine:**
   - Use a helper function to merge the two sorted halves into a single sorted array.

### **Steps**

1. If the array has more than one element:
   - Find the middle point.
   - Recursively sort the left half.
   - Recursively sort the right half.
   - Merge the two sorted halves.

---

## **Code Details**

### **Key Components**

1. **Merge Function:**
   - Merges two sorted subarrays into a single sorted array:
     ```cpp
     void merge(vector<int>& arr, int left, int mid, int right) {
         int n1 = mid - left + 1;
         int n2 = right - mid;

         vector<int> L(n1), R(n2);
         for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
         for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

         int i = 0, j = 0, k = left;
         while (i < n1 && j < n2) {
             if (L[i] <= R[j]) arr[k++] = L[i++];
             else arr[k++] = R[j++];
         }

         while (i < n1) arr[k++] = L[i++];
         while (j < n2) arr[k++] = R[j++];
     }
     ```

2. **Merge Sort Function:**
   - Recursively splits the array and sorts each half:
     ```cpp
     void mergeSort(vector<int>& arr, int left, int right) {
         if (left < right) {
             int mid = left + (right - left) / 2;
             mergeSort(arr, left, mid);
             mergeSort(arr, mid + 1, right);
             merge(arr, left, mid, right);
         }
     }
     ```

3. **Main Function:**
   - Initializes the array and sorts it:
     ```cpp
     int main() {
         vector<int> arr = {12, 11, 13, 5, 6, 7};
         mergeSort(arr, 0, arr.size() - 1);
         cout << "Sorted array: ";
         printArray(arr);
         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `merge_sort.cpp`.
2. Compile the code:
   ```bash
   g++ merge_sort.cpp -o merge_sort
   ```
3. Run the program:
   ```bash
   ./merge_sort
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded array:
```plaintext
[12, 11, 13, 5, 6, 7]
```

### **Output**
```plaintext
Sorted array: 5 6 7 11 12 13
```

---

## **Complexity**

### **Time Complexity**
- **Best, Worst, and Average Case:** \(O(n \log n)\), due to the recursive splitting and merging process.

### **Space Complexity**
- \(O(n)\): Additional space is required for the temporary arrays during merging.

---

## **Applications**

1. **Sorting Large Datasets:**
   - Ideal for external sorting (e.g., sorting data stored in files).
2. **Stable Sort:**
   - Preserves the relative order of equal elements, useful in applications where stability matters.
3. **Divide and Conquer Algorithms:**
   - Basis for solving other problems using divide-and-conquer techniques.

---

## **Advantages**

1. **Time Efficiency:**
   - Guaranteed \(O(n \log n)\) performance for all input types.
2. **Stability:**
   - Maintains the relative order of equal elements.
3. **Parallelizability:**
   - Suitable for parallel processing due to its divide-and-conquer nature.

---

## **Limitations**

1. **Space Usage:**
   - Requires additional memory for temporary arrays during merging.
2. **Not In-Place:**
   - Unlike algorithms like Quick Sort, Merge Sort does not sort the array in-place.

---

This implementation demonstrates the power and elegance of Merge Sort, providing an efficient and reliable solution for sorting arrays of any size.