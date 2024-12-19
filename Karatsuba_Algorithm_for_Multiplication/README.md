### `README.md` for Karatsuba Multiplication and String Multiplication Implementation

---

# **Karatsuba Multiplication and String Multiplication**

This project implements two methods for multiplication:
1. **Karatsuba Multiplication:** A divide-and-conquer algorithm to multiply large integers.
2. **String Multiplication:** A method to multiply numbers represented as strings, similar to manual multiplication.

---

## **Problem Description**

### **Karatsuba Multiplication**
The Karatsuba algorithm is a recursive technique for fast multiplication. It reduces the complexity of multiplication from \(O(n^2)\) (as in the classical approach) to \(O(n^{\log_2 3}) \approx O(n^{1.585})\).

### **String Multiplication**
This approach simulates manual multiplication for numbers represented as strings. It supports very large numbers that cannot be handled by standard data types.

---

## **Code Details**

### **Key Functions**

#### **Karatsuba Multiplication**
1. **Equalize Lengths of Numbers:**
   - Pads the shorter number with leading zeros:
     ```cpp
     int makeEqualLength(string& str1, string& str2) {
         int len1 = str1.size();
         int len2 = str2.size();
         if (len1 < len2) {
             str1.insert(0, len2 - len1, '0');
         } else if (len2 < len1) {
             str2.insert(0, len1 - len2, '0');
         }
         return str1.size();
     }
     ```

2. **Karatsuba Recursive Function:**
   - Recursively computes the product of two numbers:
     ```cpp
     int karatsubaMultiply(int x, int y) {
         string strX = to_string(x);
         string strY = to_string(y);
         int n = makeEqualLength(strX, strY);

         if (n == 1) return x * y;

         int mid = n / 2;
         int a = stoi(strX.substr(0, mid));
         int b = stoi(strX.substr(mid));
         int c = stoi(strY.substr(0, mid));
         int d = stoi(strY.substr(mid));

         int ac = karatsubaMultiply(a, c);
         int bd = karatsubaMultiply(b, d);
         int adbc = karatsubaMultiply(a + b, c + d) - ac - bd;

         return ac * pow(10, n) + adbc * pow(10, n / 2) + bd;
     }
     ```

#### **String Multiplication**
1. **Addition of Strings:**
   - Adds two numeric strings:
     ```cpp
     string addStrings(const string& num1, const string& num2) {
         string result;
         int carry = 0, sum;
         for (int i = num1.size() - 1; i >= 0; i--) {
             sum = (num1[i] - '0') + (num2[i] - '0') + carry;
             result.insert(result.begin(), sum % 10 + '0');
             carry = sum / 10;
         }
         if (carry) result.insert(result.begin(), carry + '0');
         return result;
     }
     ```

2. **Single-Digit Multiplication:**
   - Multiplies a string by a single digit:
     ```cpp
     string multiplySingleDigit(const string& num1, char digit) {
         string result;
         int carry = 0, product;
         for (int i = num1.size() - 1; i >= 0; i--) {
             product = (num1[i] - '0') * (digit - '0') + carry;
             result.insert(result.begin(), product % 10 + '0');
             carry = product / 10;
         }
         if (carry) result.insert(result.begin(), carry + '0');
         return result;
     }
     ```

3. **String Multiplication:**
   - Implements the multiplication of two numeric strings:
     ```cpp
     string multiplyStrings(const string& num1, const string& num2) {
         if (num1 == "0" || num2 == "0") return "0";
         string result = "0";
         for (int i = num2.size() - 1; i >= 0; i--) {
             string temp = multiplySingleDigit(num1, num2[i]);
             temp.append(num2.size() - 1 - i, '0');
             result = addStrings(result, temp);
         }
         return result;
     }
     ```

---

## **How It Works**

### **Karatsuba Algorithm**
1. Divide numbers into two halves:
   - \(x = 10^m \cdot a + b\), \(y = 10^m \cdot c + d\)
2. Compute three products:
   - \(ac, bd, (a+b)(c+d)\)
3. Use the formula:
   - \(x \cdot y = 10^{2m} \cdot ac + 10^m \cdot (ad + bc) + bd\)

### **String Multiplication**
1. Multiply each digit of one number with every digit of the other.
2. Accumulate results by aligning them according to place values.
3. Add results to get the final product.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `karatsuba_and_string_multiplication.cpp`.
2. Compile the code:
   ```bash
   g++ karatsuba_and_string_multiplication.cpp -o multiply -lm
   ```
3. Run the program:
   ```bash
   ./multiply
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded values:
```plaintext
x = 1234
y = 5678
```

### **Output**
The output displays the product using Karatsuba multiplication:
```plaintext
Karatsuba Multiplication: 7006652
```

---

## **Complexity**

### **Karatsuba Multiplication**
- **Time Complexity:** \(O(n^{\log_2 3}) \approx O(n^{1.585})\)
- **Space Complexity:** \(O(n)\) (due to recursive calls)

### **String Multiplication**
- **Time Complexity:** \(O(n^2)\)
- **Space Complexity:** \(O(n)\)

---

## **Applications**

1. **Cryptography:**
   - Efficient multiplication for large integers.
2. **Big Integer Libraries:**
   - Handling numbers beyond standard data type limits.
3. **Mathematical Software:**
   - Precise and optimized computation of large products.

---

## **Customization**

- Modify \(x\) and \(y\) in the `main()` function to test with different inputs.
- Extend string multiplication to handle decimal points for real numbers.

---

## **Limitations**

- Karatsuba is slower than traditional methods for very small inputs.
- String multiplication is computationally expensive for extremely large inputs.

---

This implementation provides an efficient way to handle both integer and string-based multiplications, leveraging the power of the Karatsuba algorithm for optimized performance.