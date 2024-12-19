### `README.md` for Longest Common Subsequence (LCS)

---

# **Longest Common Subsequence (LCS)**

This project implements the **Longest Common Subsequence (LCS)** problem in C++. LCS is a classic dynamic programming problem that finds the longest sequence common to two given strings.

---

## **Problem Description**

Given:
- Two strings \(X\) and \(Y\).

Goal:
- Find the length of the longest subsequence common to both strings.

### **Example Input**

```plaintext
X: "AGGTAB"
Y: "GXTXAYB"
```

### **Expected Output**

```plaintext
Length of LCS: 4
```

The LCS is `"GTAB"`.

---

## **How It Works**

### **Algorithm**

1. **Dynamic Programming Table:**
   - Create a 2D array \(dp[m+1][n+1]\), where:
     - \(m\) is the length of \(X\).
     - \(n\) is the length of \(Y\).
   - \(dp[i][j]\) stores the length of the LCS of the first \(i\) characters of \(X\) and the first \(j\) characters of \(Y\).

2. **Recurrence Relation:**
   - If \(X[i-1] == Y[j-1]\), then:
     \[
     dp[i][j] = dp[i-1][j-1] + 1
     \]
   - Otherwise:
     \[
     dp[i][j] = \max(dp[i-1][j], dp[i][j-1])
     \]

3. **Base Case:**
   - \(dp[0][j] = 0\) and \(dp[i][0] = 0\), as there is no common subsequence with an empty string.

4. **Result:**
   - The length of the LCS is stored in \(dp[m][n]\).

---

## **Code Details**

### **Key Components**

1. **LCS Function:**
   - Computes the length of the LCS using a dynamic programming approach:
     ```cpp
     int lcs(const string& X, const string& Y) {
         int m = X.size(), n = Y.size();
         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

         for (int i = 1; i <= m; ++i) {
             for (int j = 1; j <= n; ++j) {
                 if (X[i - 1] == Y[j - 1])
                     dp[i][j] = dp[i - 1][j - 1] + 1;
                 else
                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
             }
         }
         return dp[m][n];
     }
     ```

2. **Main Function:**
   - Defines the input strings and calls the `lcs` function:
     ```cpp
     int main() {
         string X = "AGGTAB";
         string Y = "GXTXAYB";
         cout << "Length of LCS: " << lcs(X, Y) << endl;
         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `lcs.cpp`.
2. Compile the code:
   ```bash
   g++ lcs.cpp -o lcs
   ```
3. Run the program:
   ```bash
   ./lcs
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded values:
```plaintext
X: "AGGTAB"
Y: "GXTXAYB"
```

### **Output**
```plaintext
Length of LCS: 4
```

---

## **Complexity**

### **Time Complexity**
- \(O(m \times n)\), where:
  - \(m\) is the length of string \(X\).
  - \(n\) is the length of string \(Y\).

### **Space Complexity**
- \(O(m \times n)\): For the \(dp\) table.

---

## **Applications**

1. **Text Comparison:**
   - Compare versions of documents or code files.
2. **Bioinformatics:**
   - Find similarities between DNA, RNA, or protein sequences.
3. **Spell Checking:**
   - Identify common patterns in strings.
4. **Data Compression:**
   - Detect repetitive patterns in data streams.

---

## **Customization**

- Modify the `X` and `Y` strings in the `main()` function to test with different inputs.
- Extend the code to reconstruct the LCS itself instead of just returning its length.

---

## **Advantages**

1. Efficient computation using dynamic programming.
2. Works for strings of varying lengths.

---

## **Limitations**

1. Memory usage can be high for very large strings due to the \(dp\) table.
2. Computationally intensive for extremely large inputs.

---

This implementation provides an efficient and versatile solution to the LCS problem, useful in fields like bioinformatics, text processing, and data analysis.