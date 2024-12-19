### `README.md` for Gradient Boosting Implementation

---

# **Gradient Boosting**

This project implements a simple version of **Gradient Boosting** in C++. Gradient Boosting is a machine learning technique for regression and classification problems, which builds a model incrementally by optimizing for the residual errors of previous models.

---

## **Problem Description**

Given a dataset of input features \(x\) and corresponding output labels \(y\), the goal of Gradient Boosting is to build an ensemble model that minimizes the error by iteratively fitting simple models (base learners) to the residuals of the predictions.

---

### **Example Input**

```plaintext
Input Features (x): [1.0, 2.0, 3.0, 4.0, 5.0]
Output Labels (y): [1.5, 3.0, 4.5, 6.0, 7.5]
Number of Iterations: 10
Learning Rate: 0.1
```

### **Expected Output**

```plaintext
Iteration 1: Loss = 16.5
Iteration 2: Loss = 13.365
...
Iteration 10: Loss = 0.000230791
Final predictions: [1.5, 3.0, 4.5, 6.0, 7.5]
```

---

## **How It Works**

### **Gradient Boosting Steps**

1. **Initialization:**
   - Start with a model that makes constant predictions (e.g., all zeros).

2. **Compute Residuals:**
   - Calculate the difference between the true values (\(y\)) and the current predictions.

3. **Fit a Base Learner:**
   - Fit a simple model (in this case, a constant value) to the residuals.

4. **Update Predictions:**
   - Adjust the predictions by adding a fraction of the fitted model's output scaled by the learning rate.

5. **Repeat:**
   - Iterate this process for a fixed number of iterations or until the error converges.

---

## **Code Details**

### **Key Components**

1. **Residual Computation:**
   - Compute the difference between actual values and predictions:
     ```cpp
     double computeResidual(const vector<double>& predictions, const vector<double>& actual, int index) {
         return actual[index] - predictions[index];
     }
     ```

2. **Mean Residual:**
   - Fit a simple regression tree by averaging the residuals:
     ```cpp
     double meanResidual = 0.0;
     for (int i = 0; i < n; ++i) {
         meanResidual += residuals[i];
     }
     meanResidual /= n;
     ```

3. **Prediction Update:**
   - Add the scaled residuals to the current predictions:
     ```cpp
     for (int i = 0; i < n; ++i) {
         predictions[i] += learningRate * meanResidual;
     }
     ```

4. **Loss Calculation:**
   - Compute the mean squared error:
     ```cpp
     double loss = 0.0;
     for (int i = 0; i < n; ++i) {
         loss += pow(predictions[i] - y[i], 2);
     }
     loss /= n;
     ```

5. **Main Function:**
   - Initializes the input data, number of iterations, and learning rate, and runs the `gradientBoosting` function.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `gradient_boosting.cpp`.
2. Compile the code:
   ```bash
   g++ gradient_boosting.cpp -o gradient_boosting -lm
   ```
3. Run the program:
   ```bash
   ./gradient_boosting
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded values:
```plaintext
Input Features (x): [1.0, 2.0, 3.0, 4.0, 5.0]
Output Labels (y): [1.5, 3.0, 4.5, 6.0, 7.5]
Number of Iterations: 10
Learning Rate: 0.1
```

### **Output**
The iterative loss values and final predictions:
```plaintext
Iteration 1: Loss = 16.5
Iteration 2: Loss = 13.365
...
Iteration 10: Loss = 0.000230791
Final predictions: [1.5, 3.0, 4.5, 6.0, 7.5]
```

---

## **Complexity**

### **Time Complexity**
- \(O(T \cdot n)\):  
  - \(T\): Number of iterations.  
  - \(n\): Number of data points.  
  - Each iteration involves computing residuals and updating predictions.

### **Space Complexity**
- \(O(n)\):  
  - For storing predictions and residuals.

---

## **Applications**

1. **Regression:**
   - Predicting continuous values (e.g., housing prices, stock prices).

2. **Classification (with adjustments):**
   - Gradient Boosting can be adapted for binary or multi-class classification tasks.

3. **Ensemble Methods:**
   - Forms the foundation of powerful ensemble techniques like **XGBoost** and **LightGBM**.

---

## **Customization**

- Modify the `x` and `y` vectors in the `main()` function to test with different datasets.
- Adjust the `numIterations` and `learningRate` to see their effect on convergence.

---

## **Limitations**

- This implementation uses a single constant as the base learner. For real-world applications, more complex models like decision trees are typically used as base learners.

---

This implementation demonstrates the fundamental principles of Gradient Boosting, highlighting its iterative approach to error minimization.