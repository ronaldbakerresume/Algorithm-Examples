### `README.md` for Linear Regression Implementation

---

# **Linear Regression**

This project implements **Simple Linear Regression** in C++. Linear Regression is a statistical method for modeling the relationship between two variables by fitting a straight line to the data.

---

## **Problem Description**

Given:
- A set of data points \((x, y)\), where \(x\) is the independent variable and \(y\) is the dependent variable.

Goal:
- Fit a straight line \(y = mx + b\), where:
  - \(m\) is the slope of the line.
  - \(b\) is the y-intercept.

### **Example Input**

```plaintext
x: [1, 2, 3, 4, 5]
y: [2, 4, 5, 4, 5]
```

### **Expected Output**

```plaintext
Linear Regression: y = 0.6x + 2.2
Prediction for x = 6.0: y = 5.8
```

---

## **How It Works**

### **Formulae**

1. **Slope (\(m\)):**
   \[
   m = \frac{n \cdot \sum(x \cdot y) - \sum x \cdot \sum y}{n \cdot \sum(x^2) - (\sum x)^2}
   \]

2. **Intercept (\(b\)):**
   \[
   b = \frac{\sum y - m \cdot \sum x}{n}
   \]

3. **Prediction:**
   - Use the equation of the line \(y = mx + b\) to predict \(y\) for a given \(x\).

---

## **Code Details**

### **Key Components**

1. **Linear Regression Function:**
   - Computes the slope and intercept:
     ```cpp
     pair<double, double> linearRegression(const vector<double>& x, const vector<double>& y) {
         int n = x.size();
         double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

         for (int i = 0; i < n; ++i) {
             sumX += x[i];
             sumY += y[i];
             sumXY += x[i] * y[i];
             sumX2 += x[i] * x[i];
         }

         double slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
         double intercept = (sumY - slope * sumX) / n;

         return {slope, intercept};
     }
     ```

2. **Main Function:**
   - Defines the input data and calls the `linearRegression` function:
     ```cpp
     int main() {
         vector<double> x = {1, 2, 3, 4, 5};
         vector<double> y = {2, 4, 5, 4, 5};

         auto [slope, intercept] = linearRegression(x, y);
         cout << "Linear Regression: y = " << slope << "x + " << intercept << endl;

         double predictX = 6.0;
         cout << "Prediction for x = " << predictX << ": y = " << slope * predictX + intercept << endl;

         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `linear_regression.cpp`.
2. Compile the code:
   ```bash
   g++ linear_regression.cpp -o linear_regression
   ```
3. Run the program:
   ```bash
   ./linear_regression
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded data:
```plaintext
x: [1, 2, 3, 4, 5]
y: [2, 4, 5, 4, 5]
```

### **Output**
```plaintext
Linear Regression: y = 0.6x + 2.2
Prediction for x = 6.0: y = 5.8
```

---

## **Complexity**

### **Time Complexity**
- \(O(n)\): Single pass through the data to compute the required summations.

### **Space Complexity**
- \(O(1)\): Uses constant extra space.

---

## **Applications**

1. **Predictive Analytics:**
   - Predict future outcomes based on historical data.
2. **Trend Analysis:**
   - Identify trends in time series data.
3. **Forecasting:**
   - Estimate values in fields like finance, economics, and sales.

---

## **Customization**

- Modify the `x` and `y` vectors in the `main()` function to test with different datasets.
- Extend the code to calculate additional metrics such as R-squared for goodness of fit.

---

## **Advantages**

1. Simple and interpretable model for linear relationships.
2. Efficient computation with a single pass through the data.

---

## **Limitations**

1. Assumes a linear relationship between \(x\) and \(y\).
2. Sensitive to outliers in the data.

---

This implementation of Linear Regression is a foundational tool for statistical modeling and predictive analytics, providing insights into the relationships between variables.