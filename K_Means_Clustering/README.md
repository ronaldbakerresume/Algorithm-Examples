### `README.md` for K-Means Clustering Algorithm

---

# **K-Means Clustering**

This project implements the **K-Means Clustering Algorithm** in C++. K-Means is an iterative, unsupervised machine learning algorithm used to partition data points into \(k\) distinct clusters based on their features.

---

## **Problem Description**

Given a set of data points in a multi-dimensional space, the K-Means algorithm partitions the points into \(k\) clusters by minimizing the within-cluster variance. Each cluster is represented by its centroid, and points are assigned to the cluster with the closest centroid.

### **Example Input**

```plaintext
Data Points: [(1.0, 1.0), (1.5, 2.0), (3.0, 4.0), (5.0, 7.0), (3.5, 5.0), (4.5, 5.0), (3.5, 4.5)]
Number of Clusters (k): 2
Number of Iterations: 10
```

### **Expected Output**

```plaintext
Final Clusters:
Point 1 belongs to cluster 1
Point 2 belongs to cluster 1
Point 3 belongs to cluster 2
Point 4 belongs to cluster 2
Point 5 belongs to cluster 2
Point 6 belongs to cluster 2
Point 7 belongs to cluster 2
```

---

## **How It Works**

### **Steps in K-Means Clustering**

1. **Initialize Centroids:**
   - Randomly select \(k\) data points as the initial centroids.

2. **Assign Points to Clusters:**
   - For each data point, compute the Euclidean distance to each centroid.
   - Assign the point to the cluster with the nearest centroid.

3. **Update Centroids:**
   - Compute the new centroid for each cluster as the mean of all points assigned to that cluster.

4. **Repeat:**
   - Repeat the assignment and update steps for a fixed number of iterations or until convergence.

---

## **Code Details**

### **Key Components**

1. **Euclidean Distance Function:**
   - Computes the distance between two points:
     ```cpp
     double euclideanDistance(const vector<double>& a, const vector<double>& b) {
         double sum = 0.0;
         for (int i = 0; i < a.size(); ++i) {
             sum += pow(a[i] - b[i], 2);
         }
         return sqrt(sum);
     }
     ```

2. **K-Means Function:**
   - Implements the K-Means clustering algorithm:
     ```cpp
     void kMeans(vector<vector<double>>& data, int k, int iterations) {
         int n = data.size(), dim = data[0].size();
         vector<vector<double>> centroids(k, vector<double>(dim, 0));
         vector<int> labels(n, -1);

         // Initialize centroids randomly
         srand(time(0));
         for (int i = 0; i < k; ++i) {
             centroids[i] = data[rand() % n];
         }

         for (int iter = 0; iter < iterations; ++iter) {
             // Assign each point to the closest centroid
             for (int i = 0; i < n; ++i) {
                 double minDist = 1e9;
                 for (int j = 0; j < k; ++j) {
                     double dist = euclideanDistance(data[i], centroids[j]);
                     if (dist < minDist) {
                         minDist = dist;
                         labels[i] = j;
                     }
                 }
             }

             // Update centroids
             vector<vector<double>> newCentroids(k, vector<double>(dim, 0));
             vector<int> counts(k, 0);
             for (int i = 0; i < n; ++i) {
                 for (int d = 0; d < dim; ++d) {
                     newCentroids[labels[i]][d] += data[i][d];
                 }
                 counts[labels[i]]++;
             }
             for (int j = 0; j < k; ++j) {
                 if (counts[j] > 0) {
                     for (int d = 0; d < dim; ++d) {
                         newCentroids[j][d] /= counts[j];
                     }
                 }
             }
             centroids = newCentroids;
         }

         // Output clusters
         cout << "Final Clusters:\n";
         for (int i = 0; i < n; ++i) {
             cout << "Point " << i + 1 << " belongs to cluster " << labels[i] + 1 << endl;
         }
     }
     ```

3. **Main Function:**
   - Defines the input data points, number of clusters, and iterations, and calls the `kMeans` function:
     ```cpp
     int main() {
         vector<vector<double>> data = {{1.0, 1.0}, {1.5, 2.0}, {3.0, 4.0}, {5.0, 7.0}, {3.5, 5.0}, {4.5, 5.0}, {3.5, 4.5}};
         int k = 2, iterations = 10;

         kMeans(data, k, iterations);
         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `kmeans.cpp`.
2. Compile the code:
   ```bash
   g++ kmeans.cpp -o kmeans -lm
   ```
3. Run the program:
   ```bash
   ./kmeans
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded data points:
```plaintext
Data Points: [(1.0, 1.0), (1.5, 2.0), (3.0, 4.0), (5.0, 7.0), (3.5, 5.0), (4.5, 5.0), (3.5, 4.5)]
Number of Clusters (k): 2
Number of Iterations: 10
```

### **Output**
```plaintext
Final Clusters:
Point 1 belongs to cluster 1
Point 2 belongs to cluster 1
Point 3 belongs to cluster 2
Point 4 belongs to cluster 2
Point 5 belongs to cluster 2
Point 6 belongs to cluster 2
Point 7 belongs to cluster 2
```

---

## **Complexity**

### **Time Complexity**
- **Initialization:** \(O(k)\)
- **Assignment:** \(O(n \cdot k)\) per iteration
- **Update Centroids:** \(O(n \cdot d)\) per iteration
**Overall:** \(O(\text{iterations} \cdot n \cdot (k + d))\)

### **Space Complexity**
- \(O(n + k + d)\): For centroids, labels, and data storage.

---

## **Applications**

1. **Image Segmentation:**
   - Clustering pixels based on intensity or color.

2. **Market Segmentation:**
   - Grouping customers based on purchasing behavior.

3. **Document Clustering:**
   - Organizing similar documents into categories.

4. **Anomaly Detection:**
   - Identifying points that do not belong to any cluster.

---

## **Customization**

- Modify the `data` vector in the `main()` function to test with different datasets.
- Change \(k\) to specify the number of clusters.

---

## **Limitations**

- Requires \(k\) to be predefined.
- Sensitive to the initial choice of centroids.
- May converge to a local minimum.

---

This implementation of K-Means provides a foundation for clustering analysis, with flexibility to adapt to real-world datasets and tasks.