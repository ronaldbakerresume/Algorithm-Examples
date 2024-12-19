### `README.md` for Monte Carlo Estimation of Pi

---

# **Monte Carlo Estimation of Pi**

This project demonstrates the use of the **Monte Carlo method** to estimate the value of Pi (\(\pi\)) in C++. Monte Carlo methods rely on random sampling to solve problems that might be deterministic in nature.

---

## **Problem Description**

Given:
- A unit square (\(x, y \in [0, 1]\)).
- A quarter-circle of radius 1, inscribed within the square.

Goal:
- Estimate the value of \(\pi\) by randomly sampling points within the square and calculating the ratio of points that fall inside the quarter-circle.

---

## **Mathematical Explanation**

1. **Area of the Circle:**
   - The area of a circle with radius \(r\) is \(\pi r^2\).
   - The area of the quarter-circle with \(r = 1\) is \(\frac{\pi}{4}\).

2. **Monte Carlo Simulation:**
   - Randomly generate points \((x, y)\) within the unit square.
   - Check whether each point lies inside the quarter-circle:
     \[
     x^2 + y^2 \leq 1
     \]
   - The ratio of points inside the quarter-circle to the total number of points approximates \(\frac{\pi}{4}\).

3. **Estimation:**
   - Multiply the ratio by 4 to estimate \(\pi\):
     \[
     \pi \approx 4 \times \left(\frac{\text{Points Inside Quarter-Circle}}{\text{Total Points}}\right)
     \]

---

## **Code Details**

### **Key Components**

1. **Monte Carlo Pi Function:**
   - Uses random sampling to estimate the value of \(\pi\):
     ```cpp
     double monteCarloPi(int iterations) {
         int insideCircle = 0;
         for (int i = 0; i < iterations; ++i) {
             double x = (double)rand() / RAND_MAX;
             double y = (double)rand() / RAND_MAX;
             if (x * x + y * y <= 1) {
                 insideCircle++;
             }
         }
         return 4.0 * insideCircle / iterations;
     }
     ```

2. **Main Function:**
   - Defines the number of iterations and outputs the estimated value of \(\pi\):
     ```cpp
     int main() {
         int iterations = 1000000;
         cout << "Estimated Pi: " << monteCarloPi(iterations) << endl;
         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `monte_carlo_pi.cpp`.
2. Compile the code:
   ```bash
   g++ monte_carlo_pi.cpp -o monte_carlo_pi
   ```
3. Run the program:
   ```bash
   ./monte_carlo_pi
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded value:
```plaintext
Number of Iterations: 1000000
```

### **Output**
The estimated value of Pi, for example:
```plaintext
Estimated Pi: 3.14159
```

---

## **Complexity**

### **Time Complexity**
- \(O(n)\): The simulation performs \(n\) iterations, where \(n\) is the number of random points.

### **Space Complexity**
- \(O(1)\): Uses a constant amount of memory regardless of the number of iterations.

---

## **Applications**

1. **Mathematics:**
   - Approximating mathematical constants like \(\pi\).
2. **Physics and Engineering:**
   - Solving problems with geometric probability.
3. **Data Science:**
   - Monte Carlo simulations are widely used for probabilistic modeling.

---

## **Advantages**

1. **Simplicity:**
   - Easy to implement and understand.
2. **Scalability:**
   - The accuracy improves with more iterations.

---

## **Limitations**

1. **Accuracy:**
   - Accuracy depends on the number of iterations; fewer iterations may result in significant errors.
2. **Randomness:**
   - Requires high-quality random number generation for precise results.

---

## **Customization**

- Modify the `iterations` variable in the `main` function to increase or decrease the number of random samples.

---

This implementation provides a simple yet powerful demonstration of the Monte Carlo method, illustrating how random sampling can be used to approximate complex mathematical values like \(\pi\).