### `README.md` for Insertion Sort Implementation

---

# **Insertion Sort**

This project implements the **Insertion Sort** algorithm in C++. Insertion Sort is a simple sorting algorithm that builds the sorted array one element at a time by comparing and inserting elements into their correct positions.

---

## **Problem Description**

Given an array of integers, sort the elements in ascending order using the Insertion Sort algorithm.

### **Example Input**

```plaintext
Input Array: [12, 11, 13, 5, 6]
```

### **Expected Output**

```plaintext
Sorted Array: [5, 6, 11, 12, 13]
```

---

## **How It Works**

### **Insertion Sort Steps**

1. **Iterate Through the Array:**
   - Start from the second element (index 1) and iterate to the end of the array.

2. **Compare and Shift:**
   - Compare the current element with the elements in the sorted portion of the array (to its left).
   - Shift elements in the sorted portion one position to the right until the correct position for the current element is found.

3. **Insert:**
   - Place the current element in its correct position.

4. **Repeat:**
   - Repeat for all elements in the array.

---

## **Code Details**

### **Key Components**

1. **Insertion Sort Function:**
   - Sorts the array in ascending order:
     ```cpp
     void insertionSort(vector<int>& arr) {
         int n = arr.size();
         for (int i = 1; i < n; ++i) {
             int key = arr[i];
             int j = i - 1;
             while (j >= 0 && arr[j] > key) {
                 arr[j + 1] = arr[j];
                 j--;
             }
             arr[j + 1] = key;
         }
     }
     ```

2. **Print Array Function:**
   - Prints the elements of the array:
     ```cpp
     void printArray(const vector<int>& arr) {
         for (int num : arr) cout << num << " ";
         cout << endl;
     }
     ```

3. **Main Function:**
   - Defines the input array, sorts it, and prints the result:
     ```cpp
     int main() {
         vector<int> arr = {12, 11, 13, 5, 6};
         insertionSort(arr);
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
1. Copy the code into a file named `insertion_sort.cpp`.
2. Compile the code:
   ```bash
   g++ insertion_sort.cpp -o insertion_sort
   ```
3. Run the program:
   ```bash
   ./insertion_sort
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded array:
```plaintext
Input Array: [12, 11, 13, 5, 6]
```

### **Output**
The sorted array:
```plaintext
Sorted array: 5 6 11 12 13
```

---

## **Complexity**

### **Time Complexity**
- **Best Case:** \(O(n)\):  
  - When the array is already sorted.
- **Worst Case:** \(O(n^2)\):  
  - When the array is sorted in reverse order.
- **Average Case:** \(O(n^2)\):  

### **Space Complexity**
- \(O(1)\):  
  - In-place sorting.

---

## **Applications**

1. **Small Datasets:**
   - Works efficiently for small arrays or nearly sorted data.

2. **Education:**
   - Often used to teach sorting concepts due to its simplicity.

3. **Insertion-Based Scenarios:**
   - Useful when elements are being added incrementally and need to be sorted dynamically.

---

## **Customization**

- Modify the `arr` vector in the `main()` function to test with different datasets.
- Change the comparison logic (e.g., descending order) to sort in other orders.

---

## **Advantages**

- Simple and easy to implement.
- Efficient for small datasets and nearly sorted data.

---

## **Limitations**

- Inefficient for large datasets due to \(O(n^2)\) complexity.

---

This implementation demonstrates the simplicity and utility of Insertion Sort, making it a suitable choice for small and nearly sorted datasets.