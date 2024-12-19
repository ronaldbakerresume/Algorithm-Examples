### `README.md` for Hierarchical Clustering Algorithm

---

# **Hierarchical Clustering**

This project implements a **Hierarchical Clustering Algorithm** in C++. Hierarchical clustering is a method of clustering data points by recursively grouping them into clusters based on a similarity measure (in this case, Euclidean distance).

---

## **Problem Description**

Given a set of data points in a multi-dimensional space, the goal is to group the points into a hierarchical structure of clusters. The clustering process involves merging the closest clusters iteratively until only one cluster remains.

### **Example Input**

```plaintext
Points: [(1.0, 2.0), (3.0, 4.0), (5.0, 6.0), (8.0, 9.0)]
```

### **Expected Output**

```plaintext
Merging cluster 0 with cluster 1
Merging cluster 0 with cluster 2
Merging cluster 0 with cluster 3
```

---

## **How It Works**

### **Steps in Hierarchical Clustering**

1. **Initialization:**
   - Start with each point as its own cluster.
   - Compute pairwise distances between all clusters.

2. **Find Closest Clusters:**
   - Identify the pair of clusters with the minimum distance.

3. **Merge Clusters:**
   - Combine the two closest clusters into a single cluster.
   - Update the distance matrix using the average distance between the new cluster and the remaining clusters.

4. **Repeat:**
   - Continue merging clusters until only one cluster remains.

---

## **Code Details**

### **Key Components**

1. **Distance Calculation:**
   - Computes the Euclidean distance between two points:
     ```cpp
     double euclideanDistance(const vector<double>& a, const vector<double>& b) {
         double sum = 0.0;
         for (size_t i = 0; i < a.size(); ++i) {
             sum += pow(a[i] - b[i], 2);
         }
         return sqrt(sum);
     }
     ```

2. **Finding Closest Clusters:**
   - Identifies the pair of clusters with the smallest distance:
     ```cpp
     int findMinDistanceCluster(const vector<vector<double>>& distances, const set<int>& activeClusters) {
         double minDist = 1e9;
         pair<int, int> minPair;

         for (int i : activeClusters) {
             for (int j : activeClusters) {
                 if (i != j && distances[i][j] < minDist) {
                     minDist = distances[i][j];
                     minPair = {i, j};
                 }
             }
         }

         return minPair.first * distances.size() + minPair.second; // Encode pair into single int
     }
     ```

3. **Hierarchical Clustering Function:**
   - Iteratively merges the closest clusters:
     ```cpp
     void hierarchicalClustering(vector<vector<double>>& points) {
         int n = points.size();
         vector<vector<double>> distances(n, vector<double>(n));

         // Compute initial distances
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < n; ++j) {
                 distances[i][j] = euclideanDistance(points[i], points[j]);
             }
         }

         set<int> activeClusters;
         for (int i = 0; i < n; ++i) {
             activeClusters.insert(i);
         }

         while (activeClusters.size() > 1) {
             int pairEncoded = findMinDistanceCluster(distances, activeClusters);
             int clusterA = pairEncoded / n, clusterB = pairEncoded % n;

             // Merge clusters
             cout << "Merging cluster " << clusterA << " with cluster " << clusterB << endl;
             activeClusters.erase(clusterB);

             // Update distances
             for (int i : activeClusters) {
                 if (i != clusterA) {
                     distances[clusterA][i] = distances[i][clusterA] = 
                         (distances[clusterA][i] + distances[clusterB][i]) / 2;
                 }
             }
         }
     }
     ```

4. **Main Function:**
   - Defines the input points and calls the `hierarchicalClustering` function:
     ```cpp
     int main() {
         vector<vector<double>> points = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {8.0, 9.0}};
         hierarchicalClustering(points);
         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `hierarchical_clustering.cpp`.
2. Compile the code:
   ```bash
   g++ hierarchical_clustering.cpp -o hierarchical_clustering -lm
   ```
3. Run the program:
   ```bash
   ./hierarchical_clustering
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded points:
```plaintext
Points: [(1.0, 2.0), (3.0, 4.0), (5.0, 6.0), (8.0, 9.0)]
```

### **Output**
```plaintext
Merging cluster 0 with cluster 1
Merging cluster 0 with cluster 2
Merging cluster 0 with cluster 3
```

---

## **Complexity**

### **Time Complexity**
- \(O(n^3)\):  
  - Computing pairwise distances: \(O(n^2)\)  
  - Merging clusters \(n - 1\) times, updating distances each time.

### **Space Complexity**
- \(O(n^2)\):  
  - Storing the distance matrix.

---

## **Applications**

1. **Biology:**
   - Analyzing DNA sequences and gene expression data.

2. **Market Research:**
   - Grouping customers based on purchasing behavior.

3. **Image Analysis:**
   - Clustering pixels or regions in image segmentation tasks.

4. **Social Networks:**
   - Detecting communities or closely related nodes.

---

## **Customization**

- Modify the `points` vector in the `main()` function to test with different datasets.
- Change the distance metric (e.g., Manhattan distance) for different similarity measures.

---

## **Limitations**

- Computationally expensive for large datasets due to \(O(n^3)\) complexity.
- Sensitive to the choice of distance metric.

---

This implementation demonstrates a simple yet powerful approach to hierarchical clustering, providing a foundation for more advanced clustering techniques.
