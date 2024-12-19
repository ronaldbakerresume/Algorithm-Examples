### `README.md` for Gradient Descent Implementation

---

# **Gradient Descent**

This project implements **Gradient Descent** in C++ for minimizing a simple quadratic function \(f(x) = x^2\). Gradient Descent is a widely used optimization algorithm in machine learning and mathematical optimization for finding the minimum of a function by iteratively updating its parameters in the opposite direction of the gradient.

---

## **Problem Description**

Minimize the quadratic function:
\[
f(x) = x^2
\]
where \(x\) is the parameter to optimize. The derivative (gradient) of the function is:
\[
f'(x) = 2x
\]

---

### **Example Input**

```plaintext
Initial x: 10.0
Learning Rate: 0.1
Number of Iterations: 20
```

### **Expected Output**

```plaintext
Iteration 1: x = 8, f(x) = 64
Iteration 2: x = 6.4, f(x) = 40.96
...
Iteration 20: x = 0.107374, f(x) = 0.011531
```

---

## **How It Works**

### **Gradient Descent Steps**

1. **Initialization:**
   - Start with an initial value \(x_0\).
   - Define the learning rate (\(\alpha\)) and the number of iterations.

2. **Iterative Updates:**
   - Compute the gradient of the function \(f'(x)\) at the current point \(x\).
   - Update \(x\) using:
     \[
     x = x - \alpha \cdot f'(x)
     \]
   - Repeat for the specified number of iterations.

3. **Output the Results:**
   - Print the updated value of \(x\) and the function value \(f(x)\) at each iteration.

---

## **Code Details**

### **Key Components**

1. **Gradient Function:**
   - Computes the derivative of \(f(x)\):
     ```cpp
     double gradient(double x) {
         return 2 * x; // Gradient of f(x) = x^2
     }
     ```

2. **Gradient Descent Function:**
   - Iteratively updates \(x\) using the gradient and learning rate:
     ```cpp
     void gradientDescent(double initialX, double learningRate, int iterations) {
         double x = initialX;
         for (int i = 0; i < iterations; ++i) {
             double grad = gradient(x);
             x -= learningRate * grad; // Update x
             cout << "Iteration " << i + 1 << ": x = " << x << ", f(x) = " << x * x << endl;
         }
     }
     ```

3. **Main Function:**
   - Defines the initial parameters and calls the `gradientDescent` function:
     ```cpp
     int main() {
         double initialX = 10.0;
         double learningRate = 0.1;
         int iterations = 20;
         gradientDescent(initialX, learningRate, iterations);
         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `gradient_descent.cpp`.
2. Compile the code:
   ```bash
   g++ gradient_descent.cpp -o gradient_descent -lm
   ```
3. Run the program:
   ```bash
   ./gradient_descent
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded values:
```plaintext
Initial x: 10.0
Learning Rate: 0.1
Number of Iterations: 20
```

### **Output**
The value of \(x\) and \(f(x)\) after each iteration:
```plaintext
Iteration 1: x = 8, f(x) = 64
Iteration 2: x = 6.4, f(x) = 40.96
...
Iteration 20: x = 0.107374, f(x) = 0.011531
```

---

## **Complexity**

### **Time Complexity**
- \(O(n)\):  
  - \(n\): Number of iterations.

### **Space Complexity**
- \(O(1)\):  
  - Constant space for storing variables \(x\) and the gradient.

---

## **Applications**

1. **Machine Learning:**
   - Gradient Descent is the backbone of many optimization algorithms in neural networks and linear regression.

2. **Convex Optimization:**
   - Used to find the minimum of convex functions.

3. **Physics and Engineering:**
   - Optimizing parameters in simulation and real-world systems.

---

## **Customization**

- Modify the `gradient` function to work with other functions \(f(x)\).
- Change the `initialX`, `learningRate`, and `iterations` parameters in the `main()` function to experiment with different setups.

---

## **Limitations**

- **Learning Rate Sensitivity:**
  - Too high a learning rate may cause divergence, while too low a learning rate slows convergence.
- **Non-Convex Functions:**
  - This implementation works only for convex functions. Non-convex functions may require advanced techniques to avoid local minima.

---

This implementation demonstrates the basic principles of Gradient Descent, showcasing its simplicity and effectiveness in optimizing functions. It can be extended to more complex functions and multi-dimensional parameter spaces.