### `README.md` for Selection Sort Implementation

---

# **Selection Sort Implementation**

This project provides a simple implementation of the **Selection Sort** algorithm in C++. Selection Sort is a comparison-based sorting algorithm that repeatedly selects the smallest (or largest) element from the unsorted portion of the array and places it in its correct position.

---

## **Overview**

The **Selection Sort** algorithm divides the array into two parts:
1. **Sorted portion:** Initially empty.
2. **Unsorted portion:** Contains all elements of the array.

The algorithm selects the minimum element from the unsorted portion and swaps it with the leftmost unsorted element, effectively growing the sorted portion by one element.

---

## **Key Features**
1. **Simple Logic:** The algorithm is easy to understand and implement.
2. **In-Place Sorting:** No additional memory is required beyond the input array.
3. **Fixed Time Complexity:** The algorithm always runs in \(O(n^2)\) time, regardless of input order.

---

## **Code Details**

### **Functions**

#### **`selectionSort(vector<int>& arr)`**
- **Input:** A vector of integers (`arr`) to be sorted.
- **Operation:**
  - Iterates through the array to find the minimum element in the unsorted portion.
  - Swaps the minimum element with the first unsorted element.
- **Output:** The sorted array in ascending order.

#### **`printArray(const vector<int>& arr)`**
- **Input:** A vector of integers (`arr`).
- **Operation:** Prints all elements of the array to the console.

---

## **Algorithm**

1. **Initialize the Sorted Portion:**
   - Start with an empty sorted portion.

2. **Find the Minimum Element:**
   - For each position in the array, identify the smallest element in the remaining unsorted portion.

3. **Swap and Expand the Sorted Portion:**
   - Swap the minimum element with the first unsorted element.
   - Expand the sorted portion by one.

4. **Repeat Until Sorted:**
   - Continue the process until the entire array is sorted.

---

## **Code Example**

### **Input**
```cpp
vector<int> arr = {64, 25, 12, 22, 11};
```

### **Sorting**
```cpp
selectionSort(arr);
```

### **Output**
```cpp
cout << "Sorted array: ";
printArray(arr);
```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`).

### **Steps**
1. Save the code to a file named `selection_sort.cpp`.
2. Compile the code:
   ```bash
   g++ selection_sort.cpp -o selection_sort
   ```
3. Run the program:
   ```bash
   ./selection_sort
   ```

---

## **Input/Output**

### **Input**
- Unsorted array: \([64, 25, 12, 22, 11]\)

### **Output**
```plaintext
Sorted array: 11 12 22 25 64
```

---

## **Time Complexity**
- **Best Case:** \(O(n^2)\)
- **Average Case:** \(O(n^2)\)
- **Worst Case:** \(O(n^2)\)

### **Space Complexity**
- **In-Place Sorting:** \(O(1)\)

---

## **Applications**
1. **Educational Use:** A simple algorithm to introduce sorting concepts.
2. **Small Datasets:** Efficient for sorting small arrays.
3. **Stable Inputs:** Works well when memory is constrained.

---

## **Advantages**
- Simple and easy to implement.
- In-place sorting.

---

## **Disadvantages**
- Inefficient for large datasets (\(O(n^2)\) complexity).
- Does not adapt to partially sorted inputs.

---

## **Enhancements**
- Use **Binary Selection Sort** to reduce comparisons.
- Combine with other algorithms for hybrid sorting.