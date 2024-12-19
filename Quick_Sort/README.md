### `README.md` for QuickSort Algorithm

---

# **QuickSort Algorithm**

This project demonstrates the implementation of the **QuickSort** algorithm in C++. QuickSort is a highly efficient, comparison-based sorting algorithm that uses a divide-and-conquer approach.

---

## **Overview**

QuickSort works by selecting a pivot element and partitioning the array such that:
- Elements less than or equal to the pivot are on its left.
- Elements greater than the pivot are on its right.

The process is repeated recursively for the left and right partitions.

---

## **Algorithm**

1. **Partitioning:**
   - Choose a pivot element (in this implementation, the last element is used as the pivot).
   - Rearrange the array so that:
     - All elements smaller than or equal to the pivot are placed to its left.
     - All elements greater than the pivot are placed to its right.

2. **Recursive Sorting:**
   - Recursively apply the QuickSort algorithm to the subarrays on the left and right of the pivot.

3. **Base Case:**
   - If the subarray has fewer than two elements, it is already sorted.

---

## **Code Details**

### **Key Functions**

1. **Partition Function:**
   - Rearranges the array based on the pivot:
     ```cpp
     int partition(vector<int>& arr, int low, int high) {
         int pivot = arr[high];
         int i = low - 1;

         for (int j = low; j < high; ++j) {
             if (arr[j] <= pivot) {
                 i++;
                 swap(arr[i], arr[j]);
             }
         }
         swap(arr[i + 1], arr[high]);
         return i + 1;
     }
     ```

2. **QuickSort Function:**
   - Recursively sorts the subarrays:
     ```cpp
     void quickSort(vector<int>& arr, int low, int high) {
         if (low < high) {
             int pi = partition(arr, low, high);
             quickSort(arr, low, pi - 1);
             quickSort(arr, pi + 1, high);
         }
     }
     ```

3. **Utility Function:**
   - Prints the sorted array:
     ```cpp
     void printArray(const vector<int>& arr) {
         for (int num : arr) cout << num << " ";
         cout << endl;
     }
     ```

### **Main Function**
- Initializes the array and calls `quickSort`:
  ```cpp
  int main() {
      vector<int> arr = {10, 7, 8, 9, 1, 5};
      quickSort(arr, 0, arr.size() - 1);
      cout << "Sorted array: ";
      printArray(arr);
      return 0;
  }
  ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`).

### **Steps**
1. Copy the code into a file named `quicksort.cpp`.
2. Compile the code:
   ```bash
   g++ quicksort.cpp -o quicksort
   ```
3. Run the program:
   ```bash
   ./quicksort
   ```

---

## **Input/Output**

### **Input**
- Hardcoded array:
  ```plaintext
  {10, 7, 8, 9, 1, 5}
  ```

### **Output**
- Sorted array:
  ```plaintext
  Sorted array: 1 5 7 8 9 10
  ```

---

## **Complexity**

### **Time Complexity**
1. **Best Case:** \(O(n \log n)\)  
   - Pivot divides the array into two roughly equal parts.
2. **Worst Case:** \(O(n^2)\)  
   - Pivot divides the array into one very large and one very small part (e.g., sorted or reverse-sorted array).
3. **Average Case:** \(O(n \log n)\)

### **Space Complexity**
- \(O(\log n)\) for recursive stack space.

---

## **Applications**

1. **Efficient Sorting:**
   - Ideal for large datasets.
2. **Systems Programming:**
   - Used in libraries and frameworks.
3. **Divide-and-Conquer Problems:**
   - Works well with recursion-based problems.

---

## **Limitations**

1. **Pivot Selection:**
   - Poor pivot selection can degrade performance to \(O(n^2)\).
2. **In-Place Sorting:**
   - Modifies the original array, which may not be suitable for some use cases.

---

QuickSort is a versatile and efficient sorting algorithm suitable for most practical use cases, offering a balance between speed and simplicity.