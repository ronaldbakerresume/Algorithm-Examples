### `README.md` for Random Forest Implementation

---

# **Random Forest Implementation**

This project demonstrates a simplified **Random Forest** implementation in C++ using decision trees. A Random Forest is a popular ensemble learning algorithm that builds multiple decision trees and aggregates their results for classification or regression tasks.

---

## **Overview**

Random Forest works by:
1. Creating multiple decision trees on randomly sampled subsets of the dataset.
2. Aggregating the results (majority vote for classification or average for regression).

This implementation includes:
- Random sampling of the dataset for each tree.
- Recursive construction of decision trees using a simplified ID3 algorithm.

---

## **Algorithm**

### **Steps**
1. **Dataset Sampling:**
   - Use random sampling with replacement (bootstrapping) to create subsets of the dataset for each tree.
   - Each tree receives a unique subset of the data.

2. **Decision Tree Construction:**
   - For each sampled dataset, a decision tree is built using the ID3 algorithm.

3. **Prediction Aggregation:**
   - Once all trees are constructed, predictions can be made by aggregating the output of all trees.

---

## **Code Details**

### **Key Functions**

1. **`sampleDataset`:**
   - Randomly samples the dataset with replacement:
     ```cpp
     vector<vector<int>> sampleDataset(const vector<vector<int>>& dataset, const vector<int>& labels,
                                       vector<int>& sampledLabels, int numSamples) {
         vector<vector<int>> sampledDataset;
         sampledLabels.clear();
         srand(time(0));
         for (int i = 0; i < numSamples; ++i) {
             int idx = rand() % dataset.size();
             sampledDataset.push_back(dataset[idx]);
             sampledLabels.push_back(labels[idx]);
         }
         return sampledDataset;
     }
     ```

2. **`randomForest`:**
   - Builds the forest by constructing multiple decision trees on randomly sampled datasets:
     ```cpp
     void randomForest(const vector<vector<int>>& dataset, const vector<int>& labels, int numTrees) {
         for (int t = 0; t < numTrees; ++t) {
             vector<int> sampledLabels;
             vector<vector<int>> sampledDataset = sampleDataset(dataset, labels, sampledLabels, dataset.size());

             cout << "Tree " << t + 1 << ":" << endl;
             set<int> usedFeatures;
             decisionTreeID3(sampledDataset, sampledLabels, usedFeatures);
             cout << endl;
         }
     }
     ```

3. **`decisionTreeID3`:**
   - Constructs a single decision tree using the ID3 algorithm (implemented separately).

### **Main Function**
- Calls the `randomForest` function:
  ```cpp
  int main() {
      vector<vector<int>> dataset = {{1, 1}, {1, 0}, {0, 1}, {0, 0}};
      vector<int> labels = {1, 1, 0, 0};

      int numTrees = 3;
      randomForest(dataset, labels, numTrees);

      return 0;
  }
  ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`).

### **Steps**
1. Copy the code into a file named `random_forest.cpp`.
2. Compile the code:
   ```bash
   g++ random_forest.cpp -o random_forest
   ```
3. Run the program:
   ```bash
   ./random_forest
   ```

---

## **Input/Output**

### **Input**
- **Dataset:**
  ```plaintext
  { {1, 1}, {1, 0}, {0, 1}, {0, 0} }
  ```
- **Labels:**
  ```plaintext
  { 1, 1, 0, 0 }
  ```
- **Number of Trees:**
  ```plaintext
  3
  ```

### **Output**
- Decision trees built for each sampled dataset:
  ```plaintext
  Tree 1:
  Split on Feature X

  Tree 2:
  Split on Feature Y

  Tree 3:
  Split on Feature Z
  ```

---

## **Complexity**

### **Time Complexity**
1. **Training:** \(O(t \cdot d \cdot n \cdot \log n)\)  
   - \(t\): Number of trees.
   - \(d\): Depth of each decision tree.
   - \(n\): Number of samples in the dataset.
2. **Prediction:** \(O(t \cdot d)\)

### **Space Complexity**
- \(O(t \cdot d)\) for storing all decision trees.

---

## **Applications**

1. **Classification Problems:**
   - Spam detection, sentiment analysis, and image recognition.
2. **Regression Problems:**
   - Predicting house prices or stock trends.
3. **Feature Importance:**
   - Random Forest can rank features based on their importance in classification.

---

## **Limitations**

1. **Model Size:**
   - A large number of trees can make the model memory-intensive.
2. **Overfitting:**
   - Overfitting may occur if the number of trees or tree depth is too high.

---

The Random Forest algorithm is a robust and versatile method for solving both classification and regression problems, offering excellent accuracy and resilience to overfitting.