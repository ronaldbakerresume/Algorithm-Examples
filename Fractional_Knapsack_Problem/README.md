### `README.md` for Fractional Knapsack Algorithm

---

# **Fractional Knapsack Problem**

This project implements the **Fractional Knapsack Problem** in C++. The Fractional Knapsack algorithm determines the maximum value that can be obtained by selecting items with fractional parts allowed, subject to a weight capacity constraint.

---

## **Problem Description**

Given a set of items, each with a weight and a value, and a knapsack with a maximum weight capacity, the goal is to maximize the total value of the knapsack. Unlike the 0/1 knapsack problem, fractions of items can be included.

---

### **Example Input**

```plaintext
Items: [(weight: 10, value: 60), (weight: 20, value: 100), (weight: 30, value: 120)]
Knapsack Capacity: 50
```

### **Expected Output**

```plaintext
Maximum value in Knapsack = 240.0
```

Explanation:
- Take all of item 2 (weight = 20, value = 100).
- Take all of item 3 (weight = 30, value = 120).
- Take \( \frac{2}{3} \) of item 1 (value = \( 60 \times \frac{2}{3} = 40 \)).

---

## **How It Works**

### **Key Concepts**

1. **Value-to-Weight Ratio:**
   - Calculate the ratio of value to weight for each item:
     \[
     \text{valuePerWeight} = \frac{\text{value}}{\text{weight}}
     \]

2. **Sorting:**
   - Sort items in descending order of value-to-weight ratio.

3. **Item Selection:**
   - Add items to the knapsack in the sorted order:
     - If the item fits entirely, take the whole item.
     - If not, take as much as possible from the item and stop.

4. **Output the Total Value:**
   - The sum of the selected values is the maximum achievable value.

---

## **Code Details**

### **Key Components**

1. **Item Structure:**
   - Stores the weight, value, and computed value-to-weight ratio.

2. **Comparator Function:**
   - Sorts items by their value-to-weight ratio in descending order.

3. **Fractional Knapsack Function:**
   - Implements the greedy algorithm to maximize the knapsack value.

4. **Main Function:**
   - Initializes the input items and capacity, and computes the result.

---

### **Code Walkthrough**

#### **Item Structure**

```cpp
struct Item {
    int weight, value;
    double valuePerWeight;
};
```
- Each item has a `weight`, `value`, and a computed `valuePerWeight`.

#### **Comparator Function**

```cpp
bool compareItems(const Item& a, const Item& b) {
    return a.valuePerWeight > b.valuePerWeight;
}
```
- Ensures items are sorted by their value-to-weight ratio in descending order.

#### **Fractional Knapsack Function**

```cpp
double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compareItems);

    double maxValue = 0.0;
    for (const auto& item : items) {
        if (capacity >= item.weight) {
            maxValue += item.value;
            capacity -= item.weight;
        } else {
            maxValue += capacity * item.valuePerWeight;
            break;
        }
    }
    return maxValue;
}
```
1. Sorts the items by `valuePerWeight`.
2. Iteratively adds items to the knapsack:
   - Fully if they fit.
   - Partially if capacity is exceeded.

#### **Main Function**

```cpp
int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    for (auto& item : items) {
        item.valuePerWeight = (double)item.value / item.weight;
    }

    int capacity = 50;
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(capacity, items) << endl;
    return 0;
}
```
- Initializes the items and computes their `valuePerWeight`.
- Calls `fractionalKnapsack` with the input capacity and items.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `fractional_knapsack.cpp`.
2. Compile the code:
   ```bash
   g++ fractional_knapsack.cpp -o fractional_knapsack
   ```
3. Run the program:
   ```bash
   ./fractional_knapsack
   ```

---

## **Input/Output**

### **Input**
The program uses the following items and knapsack capacity:
```plaintext
Items:
    - Weight: 10, Value: 60
    - Weight: 20, Value: 100
    - Weight: 30, Value: 120
Knapsack Capacity: 50
```

### **Output**
```plaintext
Maximum value in Knapsack = 240
```

---

## **Complexity**

### **Time Complexity**
- **Sorting:** \(O(n \log n)\)  
- **Selection:** \(O(n)\)  
**Overall:** \(O(n \log n)\)

### **Space Complexity**
- \(O(1)\): In-place sorting of the items.

---

## **Applications**

1. **Resource Allocation:**
   - Optimizing resource usage in constrained environments.

2. **Investment Decisions:**
   - Selecting projects or investments to maximize returns under a budget.

3. **Logistics:**
   - Packing containers with maximum value-to-weight efficiency.

---

## **Customization**

- Modify the `items` vector in the `main()` function to test with different datasets.
- Change the `capacity` variable to test with different knapsack capacities.

---

This implementation of the Fractional Knapsack Problem demonstrates the power of the greedy algorithm for optimizing selection problems. It is an efficient and practical approach for real-world optimization tasks.