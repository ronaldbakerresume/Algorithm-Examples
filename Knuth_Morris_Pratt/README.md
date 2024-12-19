### `README.md` for Knuth-Morris-Pratt (KMP) String Matching Algorithm

---

# **Knuth-Morris-Pratt (KMP) Algorithm**

This project implements the **Knuth-Morris-Pratt (KMP)** string matching algorithm in C++. The KMP algorithm efficiently searches for occurrences of a "pattern" string within a "text" string by leveraging the properties of the pattern.

---

## **Problem Description**

Given:
- A **text** string where the search will occur.
- A **pattern** string to search for within the text.

Goal:
- Find all occurrences of the pattern in the text.

### **Example Input**

```plaintext
Text:    "ABABDABACDABABCABAB"
Pattern: "ABABCABAB"
```

### **Expected Output**

```plaintext
Pattern found at index 10
```

---

## **How It Works**

### **Knuth-Morris-Pratt Algorithm**

1. **Preprocess the Pattern:**
   - Compute the **Longest Prefix Suffix (LPS) Array**, which represents the longest proper prefix of the pattern that is also a suffix for substrings of the pattern.
   - The LPS array helps avoid redundant comparisons.

2. **Search the Text:**
   - Traverse the text, matching characters with the pattern.
   - When a mismatch occurs, use the LPS array to determine the next position to resume the search without re-checking characters already matched.

3. **Repeat:**
   - Continue until the end of the text is reached.

---

## **Code Details**

### **Key Functions**

1. **Compute LPS Array:**
   - Prepares the LPS array:
     ```cpp
     void computeLPSArray(const string& pattern, vector<int>& lps) {
         int length = 0, i = 1;
         lps[0] = 0;

         while (i < pattern.size()) {
             if (pattern[i] == pattern[length]) {
                 lps[i++] = ++length;
             } else if (length != 0) {
                 length = lps[length - 1];
             } else {
                 lps[i++] = 0;
             }
         }
     }
     ```

2. **KMP Search:**
   - Uses the LPS array to search the text:
     ```cpp
     void KMP(const string& text, const string& pattern) {
         int m = pattern.size(), n = text.size();
         vector<int> lps(m, 0);

         computeLPSArray(pattern, lps);

         int i = 0, j = 0;
         while (i < n) {
             if (pattern[j] == text[i]) {
                 i++, j++;
             }
             if (j == m) {
                 cout << "Pattern found at index " << i - j << endl;
                 j = lps[j - 1];
             } else if (i < n && pattern[j] != text[i]) {
                 j ? j = lps[j - 1] : i++;
             }
         }
     }
     ```

3. **Main Function:**
   - Defines the input text and pattern, and invokes the `KMP` function:
     ```cpp
     int main() {
         string text = "ABABDABACDABABCABAB";
         string pattern = "ABABCABAB";

         KMP(text, pattern);
         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `kmp.cpp`.
2. Compile the code:
   ```bash
   g++ kmp.cpp -o kmp
   ```
3. Run the program:
   ```bash
   ./kmp
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded values:
```plaintext
Text:    "ABABDABACDABABCABAB"
Pattern: "ABABCABAB"
```

### **Output**
```plaintext
Pattern found at index 10
```

---

## **Complexity**

### **Time Complexity**
1. **Preprocessing (LPS Array):** \(O(m)\)  
   - \(m\): Length of the pattern.
2. **Search:** \(O(n)\)  
   - \(n\): Length of the text.

**Overall Complexity:** \(O(n + m)\)

### **Space Complexity**
- \(O(m)\): For the LPS array.

---

## **Applications**

1. **Search Engines:**
   - Efficiently find substrings within text documents.
2. **Bioinformatics:**
   - Pattern matching in DNA sequences.
3. **Compilers:**
   - Identifying tokens in source code.

---

## **Customization**

- Modify the `text` and `pattern` variables in the `main()` function to test with different inputs.

---

## **Advantages**

1. Linear time complexity ensures efficient performance for long texts and patterns.
2. Avoids redundant comparisons by leveraging the LPS array.

---

## **Limitations**

- Requires preprocessing of the pattern, which adds overhead for small patterns.

---

This implementation of the KMP algorithm demonstrates its efficiency and utility in solving pattern-matching problems in linear time.