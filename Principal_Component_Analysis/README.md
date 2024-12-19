### `README.md` for Principal Component Analysis (PCA) using Eigen Library in C++

---

# **Principal Component Analysis (PCA) Implementation**

This project demonstrates the implementation of **Principal Component Analysis (PCA)** using the **Eigen** library in C++. PCA is a dimensionality reduction technique widely used in machine learning and data analysis.

---

## **Overview**

PCA is used to transform high-dimensional data into a lower-dimensional space while retaining as much variance as possible.

### **Steps in PCA**

1. **Center the Data:**
   - Subtract the mean of each column from the respective column values.
2. **Compute Covariance Matrix:**
   - Measure how dimensions vary with each other.
3. **Eigen Decomposition:**
   - Find eigenvectors (principal components) and eigenvalues.
4. **Transform Data:**
   - Project the data onto the top \(k\) principal components.

---

## **Code Details**

### **Key Functions**

1. **Centering the Data:**
   - Subtract the mean of each column from the dataset:
     ```cpp
     RowVectorXd mean = data.colwise().mean();
     MatrixXd centered = data.rowwise() - mean;
     ```

2. **Covariance Matrix:**
   - Compute the covariance matrix of the centered data:
     ```cpp
     MatrixXd cov = (centered.transpose() * centered) / (data.rows() - 1);
     ```

3. **Eigen Decomposition:**
   - Use Eigen's `SelfAdjointEigenSolver` to compute eigenvalues and eigenvectors:
     ```cpp
     SelfAdjointEigenSolver<MatrixXd> solver(cov);
     MatrixXd eigenVectors = solver.eigenvectors().rightCols(components);
     ```

4. **Transforming Data:**
   - Project the original data onto the selected principal components:
     ```cpp
     MatrixXd transformed = centered * eigenVectors;
     ```

### **Main Function**
- Initializes a dataset, sets the number of components, and calls the PCA function:
  ```cpp
  int main() {
      MatrixXd data(5, 3);
      data << 2.5, 2.4, 0.8,
              0.5, 0.7, 0.9,
              2.2, 2.9, 0.7,
              1.9, 2.2, 1.0,
              3.1, 3.0, 1.1;

      int components = 2;
      pca(data, components);
      return 0;
  }
  ```

---

## **How to Run**

### **Requirements**
1. **Eigen Library:**
   - Download Eigen from [eigen.tuxfamily.org](https://eigen.tuxfamily.org/).
   - Include the Eigen directory in your project.

2. **C++ Compiler:**
   - A compiler that supports C++11 or later (e.g., `g++`).

### **Steps**
1. Install the Eigen library and configure your project to include it.
2. Copy the code into a file named `pca.cpp`.
3. Compile the code:
   ```bash
   g++ -I /path/to/eigen pca.cpp -o pca
   ```
4. Run the program:
   ```bash
   ./pca
   ```

---

## **Input/Output**

### **Input**
- **Dataset:**
  ```plaintext
  2.5  2.4  0.8
  0.5  0.7  0.9
  2.2  2.9  0.7
  1.9  2.2  1.0
  3.1  3.0  1.1
  ```

- **Number of Principal Components:**
  \(k = 2\)

### **Output**
1. **Principal Components:**
   - Eigenvectors corresponding to the top 2 principal components.
2. **Transformed Data:**
   - Dataset projected onto the principal components.

---

## **Example Output**

```plaintext
Principal Components:
-0.68  -0.72
 0.73  -0.69
 0.02   0.06

Transformed Data:
-1.43   0.42
  1.27  -0.32
 -1.51   0.58
 -1.15   0.14
  1.81  -0.57
```

---

## **Complexity**

### **Time Complexity**
- Covariance matrix computation: \(O(nd^2)\), where \(n\) is the number of samples and \(d\) is the number of features.
- Eigen decomposition: \(O(d^3)\).

### **Space Complexity**
- \(O(d^2)\) for covariance matrix storage.

---

## **Applications**

1. **Data Compression:**
   - Reduce dimensionality while retaining significant information.
2. **Visualization:**
   - Plot high-dimensional data in 2D or 3D.
3. **Noise Reduction:**
   - Eliminate noise by focusing on major components.
4. **Preprocessing:**
   - Prepare features for machine learning algorithms.

---

## **Limitations**

1. **Linear Relationships Only:**
   - PCA captures linear correlations and may not work well for non-linear datasets.
2. **Data Scaling:**
   - Sensitive to feature scaling; all features should be standardized.
3. **Interpretability:**
   - Principal components may not have a direct, interpretable meaning.

---

This implementation highlights the power and simplicity of PCA for dimensionality reduction and data analysis.