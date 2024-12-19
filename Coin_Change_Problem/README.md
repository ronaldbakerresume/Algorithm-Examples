### `README.md` for Coin Change Problem

---

# **Coin Change Problem**

This project implements a solution to the **Coin Change Problem** using **Dynamic Programming** in C++. The goal is to determine the minimum number of coins required to make up a given amount, or determine if it is impossible to make up the amount using the available coin denominations.

---

## **Problem Description**

Given a list of coin denominations and a target amount, the task is to find the minimum number of coins required to make up the target amount. If it is not possible to make the amount, return \(-1\).

### **Example Input**
```plaintext
Coins: [1, 2, 5]
Amount: 11
```

### **Expected Output**
```plaintext
Minimum coins required: 3
```

Explanation:
- Use \(5 + 5 + 1 = 11\) (3 coins in total).

---

## **How It Works**

1. **Dynamic Programming Array (`dp`):**
   - Create a `dp` array of size \( \text{amount} + 1 \), where `dp[i]` represents the minimum number of coins required to make up the amount \(i\).
   - Initialize the array with a large value (`amount + 1`), except for `dp[0] = 0` (0 coins needed to make amount 0).

2. **Iterate Over All Amounts:**
   - For each amount from 1 to `amount`:
     - Check each coin denomination. If the coin can be used (\(i \geq \text{coin}\)):
       - Update `dp[i]` as:
         \[
         dp[i] = \min(dp[i], dp[i - \text{coin}] + 1)
         \]

3. **Result:**
   - After processing, if `dp[amount]` is still greater than `amount`, no solution is possible. Otherwise, `dp[amount]` contains the minimum number of coins needed.

---

## **Code Details**

### **Key Components**

1. **Dynamic Programming Array:**
   - The `dp` array stores the minimum coins required for every amount from 0 to `amount`.

2. **Coin Iteration:**
   - Each coin denomination is considered for every amount to find the optimal solution.

3. **Main Function:**
   - Initializes the coin denominations and target amount.
   - Calls the `coinChange` function to calculate the result.

---

### **Code Walkthrough**

#### **Dynamic Programming Function**
```cpp
int coinChange(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1); // Initialize dp array
    dp[0] = 0; // 0 coins needed for amount 0

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin) // Check if coin can be used
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
```
- The outer loop iterates over all amounts.
- The inner loop iterates over all coin denominations to update the `dp` array.

#### **Main Function**
```cpp
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = coinChange(coins, amount);

    if (result != -1)
        cout << "Minimum coins required: " << result << endl;
    else
        cout << "No solution possible." << endl;

    return 0;
}
```
- Defines the coin denominations and the target amount.
- Calls `coinChange` to compute the result and prints the outcome.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `coin_change.cpp`.
2. Compile the code:
   ```bash
   g++ coin_change.cpp -o coin_change
   ```
3. Run the program:
   ```bash
   ./coin_change
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded input:
```cpp
vector<int> coins = {1, 2, 5};
int amount = 11;
```

### **Output**
```plaintext
Minimum coins required: 3
```

If a solution is not possible (e.g., `amount = 7` and `coins = {2, 4}`), the output will be:
```plaintext
No solution possible.
```

---

## **Complexity**

### **Time Complexity**
- \(O(\text{amount} \times \text{number of coins})\):
  - The outer loop iterates over all amounts (\(O(\text{amount})\)).
  - The inner loop iterates over all coin denominations.

### **Space Complexity**
- \(O(\text{amount})\):
  - The `dp` array requires space proportional to the target amount.

---

## **Applications**

1. **Finance:**
   - Calculating the minimum coins or bills required for a transaction.

2. **Resource Optimization:**
   - Determining the least number of resources needed to fulfill a target.

3. **Gaming and Puzzles:**
   - Problems involving combinations and minimum resources.

---

## **Customization**

- Modify the `coins` vector to use different denominations.
- Change the `amount` to solve for other target values.

---

This implementation provides an efficient solution to the Coin Change problem using dynamic programming, showcasing its power in solving optimization problems.