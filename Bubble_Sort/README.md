### `README.md` for Bubble Sort Algorithm

---

# **Bubble Sort Algorithm**

This project implements the **Bubble Sort** algorithm in C++. Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

---

## **Problem Description**

Given an array of integers, the goal is to sort the array in ascending order using the Bubble Sort algorithm.

### **Example Input**
```plaintext
Array: [64, 34, 25, 12, 22, 11, 90]
```

### **Expected Output**
```plaintext
Sorted array: [11, 12, 22, 25, 34, 64, 90]
```

---

## **How It Works**

1. **Iterate Over the Array:**
   - Perform multiple passes over the array.

2. **Compare Adjacent Elements:**
   - Compare each pair of adjacent elements. If the left element is greater than the right element, swap them.

3. **Largest Elements "Bubble Up":**
   - With each pass, the largest unsorted element is moved to its correct position at the end of the array.

4. **Stop Early (Optional Optimization):**
   - If no swaps occur during a pass, the array is already sorted, and the algorithm can terminate early (not implemented in this code but can be added).

---

## **Code Details**

### **Key Components**

1. **`bubbleSort` Function:**
   - Iteratively compares and swaps adjacent elements.

2. **`printArray` Function:**
   - Prints the elements of the array.

3. **`main` Function:**
   - Initializes the array, calls the `bubbleSort` function, and prints the sorted array.

---

### **Code Walkthrough**

#### **Bubble Sort**
```cpp
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```
- Outer loop: Ensures \(n-1\) passes over the array.
- Inner loop: Compares adjacent elements and swaps them if they are in the wrong order.

#### **Print Function**
```cpp
void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}
```
Prints the elements of the array in a single line.

#### **Main Function**
```cpp
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
```
- Initializes the input array.
- Sorts the array using `bubbleSort()`.
- Outputs the sorted array using `printArray()`.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `bubble_sort.cpp`.
2. Compile the code:
   ```bash
   g++ bubble_sort.cpp -o bubble_sort
   ```
3. Run the program:
   ```bash
   ./bubble_sort
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded array:
```cpp
vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
```

### **Output**
The sorted array:
```plaintext
Sorted array: 11 12 22 25 34 64 90
```

---

## **Complexity**

### **Time Complexity**
- **Best Case:** \(O(n^2)\) (No optimization for already sorted arrays in this implementation).
- **Worst Case:** \(O(n^2)\) (Swaps required for every adjacent pair).
- **Average Case:** \(O(n^2)\)

### **Space Complexity**
- \(O(1)\): Sorting is performed in-place without additional memory.

---

## **Applications**

1. **Teaching and Learning:**
   - Bubble Sort is commonly used to teach the fundamentals of sorting algorithms.

2. **Small Datasets:**
   - Suitable for small datasets where simplicity is more important than performance.

3. **Initial Approach:**
   - Used as a baseline to compare more advanced sorting algorithms.

---

## **Customization**

- Modify the input array in the `main()` function to test with different datasets.
- Implement an optimization to terminate the algorithm early if no swaps occur during a pass.

---

## **Limitations**

- Inefficient for large datasets due to its \(O(n^2)\) time complexity.
- Better sorting algorithms, such as Quick Sort or Merge Sort, should be used for larger datasets.

---

This implementation of Bubble Sort demonstrates a simple, yet clear approach to sorting and provides a stepping stone for understanding more advanced algorithms.