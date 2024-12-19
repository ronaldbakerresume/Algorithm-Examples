### `README.md` for Knapsack Problem (0/1 Knapsack)

---

# **Knapsack Problem (0/1 Knapsack)**

This project implements the **0/1 Knapsack Problem** in C++ using dynamic programming. The problem involves selecting items to maximize the total value in a knapsack of limited capacity, where each item can either be included or excluded entirely.

---

## **Problem Description**

Given:
- A set of items, each with a weight and a value.
- A knapsack with a maximum weight capacity \(W\).

Goal:
- Maximize the total value of items included in the knapsack without exceeding the weight capacity.

### **Example Input**

```plaintext
Weights: [1, 2, 3]
Values: [60, 100, 120]
Knapsack Capacity: 5
```

### **Expected Output**

```plaintext
Maximum value in Knapsack: 220
```

---

## **How It Works**

### **Dynamic Programming Approach**

1. **Define the DP Table:**
   - Let `dp[i][w]` represent the maximum value that can be achieved with the first \(i\) items and a weight capacity \(w\).

2. **Transition Relation:**
   - For each item \(i\) and weight \(w\):
     - If the item's weight is greater than \(w\), exclude the item:
       \[
       dp[i][w] = dp[i-1][w]
       \]
     - Otherwise, choose the maximum of excluding or including the item:
       \[
       dp[i][w] = \max(dp[i-1][w], \text{value}[i-1] + dp[i-1][w-\text{weight}[i-1]])
       \]

3. **Initialization:**
   - For \(i = 0\) or \(w = 0\), the maximum value is 0:
     \[
     dp[0][w] = dp[i][0] = 0
     \]

4. **Result:**
   - The result is stored in `dp[n][W]`, where \(n\) is the number of items.

---

## **Code Details**

### **Key Components**

1. **Knapsack Function:**
   - Implements the dynamic programming solution:
     ```cpp
     int knapsack(const vector<int>& weights, const vector<int>& values, int W) {
         int n = weights.size();
         vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

         for (int i = 1; i <= n; ++i) {
             for (int w = 0; w <= W; ++w) {
                 if (weights[i - 1] <= w)
                     dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
                 else
                     dp[i][w] = dp[i - 1][w];
             }
         }
         return dp[n][W];
     }
     ```

2. **Main Function:**
   - Defines the input weights, values, and knapsack capacity, and calls the `knapsack` function:
     ```cpp
     int main() {
         vector<int> weights = {1, 2, 3};
         vector<int> values = {60, 100, 120};
         int W = 5;

         cout << "Maximum value in Knapsack: " << knapsack(weights, values, W) << endl;
         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `knapsack.cpp`.
2. Compile the code:
   ```bash
   g++ knapsack.cpp -o knapsack
   ```
3. Run the program:
   ```bash
   ./knapsack
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded input:
```plaintext
Weights: [1, 2, 3]
Values: [60, 100, 120]
Knapsack Capacity: 5
```

### **Output**
```plaintext
Maximum value in Knapsack: 220
```

---

## **Complexity**

### **Time Complexity**
- \(O(n \cdot W)\):  
  - \(n\): Number of items.  
  - \(W\): Maximum weight capacity.

### **Space Complexity**
- \(O(n \cdot W)\):  
  - For the DP table.

---

## **Applications**

1. **Resource Allocation:**
   - Optimizing resource usage under constraints.

2. **Inventory Management:**
   - Selecting items to store or transport based on value and weight.

3. **Finance:**
   - Portfolio optimization for maximum returns under budget constraints.

4. **Project Selection:**
   - Choosing projects to maximize benefits within a budget.

---

## **Customization**

- Modify the `weights`, `values`, and `W` variables in the `main()` function to test with different inputs.
- Extend to track which items are included in the optimal solution.

---

## **Limitations**

- Does not handle fractional weights (for fractional weights, use the **Fractional Knapsack Problem** with a greedy approach).
- Memory-intensive for very large inputs.

---

This implementation of the 0/1 Knapsack Problem demonstrates the power of dynamic programming in solving optimization problems efficiently.