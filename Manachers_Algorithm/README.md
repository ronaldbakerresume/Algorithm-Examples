### `README.md` for Longest Palindromic Substring (Manacher's Algorithm)

---

# **Longest Palindromic Substring**

This project implements the **Longest Palindromic Substring** problem using **Manacher's Algorithm** in C++. Manacher's Algorithm finds the longest palindromic substring in linear time.

---

## **Problem Description**

Given:
- A string \(s\).

Goal:
- Find the longest substring of \(s\) that reads the same backward as forward.

### **Example Input**

```plaintext
Input: "babad"
```

### **Expected Output**

```plaintext
Output: "bab" (or "aba", as both are valid)
```

---

## **How It Works**

### **Algorithm**

Manacher's Algorithm works by transforming the string to include separators and then expanding around potential centers efficiently.

1. **Preprocessing:**
   - Insert special characters (#) between characters and at the boundaries to handle both even-length and odd-length palindromes uniformly.
   - Example:
     - Input: `"babad"`
     - Transformed: `"^#b#a#b#a#d#$"`

2. **Expand Around Centers:**
   - Use a vector `p` to store the radius of the palindrome centered at each position.
   - Maintain a `center` and `right` boundary for the rightmost palindrome.

3. **Dynamic Expansion:**
   - For each position \(i\):
     - Mirror the palindrome if \(i < \text{right}\).
     - Expand around \(i\) to find the palindrome length.

4. **Find Longest Palindrome:**
   - Use the maximum radius in `p` to determine the start and length of the longest palindrome in the original string.

---

## **Code Details**

### **Key Components**

1. **Preprocessing:**
   - Transforms the input string to include separators:
     ```cpp
     string preprocess(const string& s) {
         string t = "^";
         for (char c : s) {
             t += "#" + string(1, c);
         }
         t += "#$";
         return t;
     }
     ```

2. **Manacher's Algorithm:**
   - Uses a linear approach to find the longest palindromic substring:
     ```cpp
     string longestPalindrome(const string& s) {
         string t = preprocess(s);
         int n = t.size();
         vector<int> p(n, 0);
         int center = 0, right = 0;

         for (int i = 1; i < n - 1; ++i) {
             int mirror = 2 * center - i;

             if (i < right) p[i] = min(right - i, p[mirror]);

             while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;

             if (i + p[i] > right) {
                 center = i;
                 right = i + p[i];
             }
         }

         int maxLen = 0, centerIdx = 0;
         for (int i = 1; i < n - 1; ++i) {
             if (p[i] > maxLen) {
                 maxLen = p[i];
                 centerIdx = i;
             }
         }

         int start = (centerIdx - maxLen) / 2;
         return s.substr(start, maxLen);
     }
     ```

3. **Main Function:**
   - Runs the algorithm with a sample string:
     ```cpp
     int main() {
         string s = "babad";
         cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `longest_palindrome.cpp`.
2. Compile the code:
   ```bash
   g++ longest_palindrome.cpp -o longest_palindrome
   ```
3. Run the program:
   ```bash
   ./longest_palindrome
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded value:
```plaintext
s = "babad"
```

### **Output**
```plaintext
Longest Palindromic Substring: bab
```

---

## **Complexity**

### **Time Complexity**
- \(O(n)\): The algorithm processes each character in the transformed string once.

### **Space Complexity**
- \(O(n)\): Additional space for the transformed string and `p` array.

---

## **Applications**

1. **String Processing:**
   - Identify palindromes in DNA sequences or text data.
2. **Text Analysis:**
   - Search for symmetrical patterns in documents or logs.
3. **Pattern Matching:**
   - Solve substring matching problems efficiently.

---

## **Advantages**

1. Efficient \(O(n)\) time complexity.
2. Handles both even-length and odd-length palindromes seamlessly.

---

## **Limitations**

1. Implementation complexity is higher compared to naive \(O(n^2)\) methods.
2. Requires preprocessing, which may increase space usage.

---

This implementation demonstrates a highly efficient solution to finding the longest palindromic substring using Manacher's Algorithm. It is suitable for applications requiring fast palindrome detection in large datasets.