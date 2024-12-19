### `README.md` for Rabin-Karp String Matching Algorithm

---

# **Rabin-Karp String Matching Algorithm**

This project demonstrates the implementation of the **Rabin-Karp algorithm** for string matching in C++. Rabin-Karp is an efficient method for finding a pattern within a text using hashing.

---

## **Overview**

The Rabin-Karp algorithm uses a rolling hash to efficiently compare substrings of the text to the pattern. Instead of directly comparing strings, it computes hash values for the pattern and substrings of the text and compares these hashes.

### **Key Features**
1. **Hashing:**  
   - Calculate the hash of the pattern and the current substring of the text.
2. **Rolling Hash:**  
   - Update the hash in \(O(1)\) time for the next substring.
3. **String Matching:**  
   - Compare the hash values, and if they match, perform a direct string comparison to confirm the match.

---

## **Algorithm**

### **Steps**
1. **Hash Calculation:**
   - Compute the hash of the pattern and the first substring of the text.
2. **Sliding Window:**
   - Slide the window over the text and compute the rolling hash for the next substring.
3. **Hash Comparison:**
   - If the hash matches the pattern's hash, compare the strings to avoid hash collisions.
4. **Repeat Until Match:**
   - Repeat the process until all possible substrings are checked.

### **Edge Cases**
1. Handle hash collisions by comparing substrings directly.
2. Ensure the algorithm works for overlapping patterns.

---

## **Code Details**

### **Key Functions**

1. **`createHash`:**  
   Computes the hash of a string up to a given length:
   ```cpp
   int createHash(const string& str, int end) {
       int hash = 0;
       for (int i = 0; i < end; ++i) {
           hash += str[i] * pow(PRIME, i);
       }
       return hash;
   }
   ```

2. **`recalculateHash`:**  
   Updates the hash when sliding the window:
   ```cpp
   int recalculateHash(const string& str, int oldIndex, int newIndex, int oldHash, int patternLen) {
       oldHash -= str[oldIndex];
       oldHash /= PRIME;
       oldHash += str[newIndex] * pow(PRIME, patternLen - 1);
       return oldHash;
   }
   ```

3. **`checkEquality`:**  
   Compares two strings to confirm a match:
   ```cpp
   bool checkEquality(const string& str1, int start1, int end1, const string& str2) {
       if (end1 - start1 + 1 != str2.size()) return false;
       for (int i = start1; i <= end1; ++i) {
           if (str1[i] != str2[i - start1]) return false;
       }
       return true;
   }
   ```

4. **`rabinKarp`:**  
   Implements the Rabin-Karp algorithm:
   ```cpp
   void rabinKarp(const string& text, const string& pattern) {
       int m = pattern.size(), n = text.size();
       int patternHash = createHash(pattern, m);
       int textHash = createHash(text, m);

       for (int i = 0; i <= n - m; ++i) {
           if (patternHash == textHash && checkEquality(text, i, i + m - 1, pattern)) {
               cout << "Pattern found at index " << i << endl;
           }
           if (i < n - m) {
               textHash = recalculateHash(text, i, i + m, textHash, m);
           }
       }
   }
   ```

### **Main Function**
- Calls the `rabinKarp` function with the text and pattern:
  ```cpp
  int main() {
      string text = "GEEKS FOR GEEKS";
      string pattern = "GEEK";

      rabinKarp(text, pattern);
      return 0;
  }
  ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`).

### **Steps**
1. Copy the code into a file named `rabin_karp.cpp`.
2. Compile the code:
   ```bash
   g++ rabin_karp.cpp -o rabin_karp
   ```
3. Run the program:
   ```bash
   ./rabin_karp
   ```

---

## **Input/Output**

### **Input**
- **Text:** `"GEEKS FOR GEEKS"`  
- **Pattern:** `"GEEK"`

### **Output**
- Prints the indices where the pattern is found:
  ```plaintext
  Pattern found at index 0
  Pattern found at index 10
  ```

---

## **Complexity**

### **Time Complexity**
1. **Best/Average Case:** \(O(n + m)\)  
   - \(n\) is the length of the text, and \(m\) is the length of the pattern.
2. **Worst Case:** \(O(nm)\)  
   - Occurs when hash collisions are frequent, requiring direct string comparisons.

### **Space Complexity**
- \(O(1)\): Additional space for hash calculations.

---

## **Applications**

1. **Text Search:**
   - Efficiently find patterns in large text files.
2. **Plagiarism Detection:**
   - Check for matches in documents.
3. **Genome Sequence Matching:**
   - Identify matching DNA or protein sequences.

---

## **Limitations**

1. **Hash Collisions:**
   - May require additional comparisons, affecting efficiency.
2. **Sensitive to PRIME Selection:**
   - Proper selection of the PRIME value is essential to minimize collisions.

---

The Rabin-Karp algorithm is a powerful tool for string matching tasks, offering a balance of efficiency and simplicity for large-scale pattern searches.