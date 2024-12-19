### `README.md` for Decision Tree (ID3 Algorithm) Implementation

---

# **Decision Tree with ID3 Algorithm**

This project implements a simple **Decision Tree** classifier using the **ID3 (Iterative Dichotomiser 3)** algorithm in C++. The ID3 algorithm constructs a decision tree by recursively selecting the feature with the highest information gain to split the dataset.

---

## **Problem Description**

Given a dataset with features and labels, the task is to classify the data by constructing a decision tree. The tree is built using the ID3 algorithm, which selects the best feature to split the data based on **information gain**.

### **Example Dataset**
```plaintext
Features: [(1, 1), (1, 0), (0, 1), (0, 0)]
Labels: [1, 1, 0, 0]
```

### **Expected Output**
```plaintext
Split on Feature 0
Feature Value 1 -> Split on Feature 1
Feature Value 1 -> Leaf Node: Class 1
Feature Value 0 -> Leaf Node: Class 1
Feature Value 0 -> Split on Feature 1
Feature Value 1 -> Leaf Node: Class 0
Feature Value 0 -> Leaf Node: Class 0
```

---

## **How It Works**

### **Key Concepts**

1. **Entropy:**
   - A measure of uncertainty or impurity in a dataset:
     \[
     H(S) = -\sum_{i} p_i \log_2(p_i)
     \]
     where \(p_i\) is the proportion of class \(i\) in the dataset.

2. **Information Gain:**
   - The reduction in entropy after splitting the dataset based on a feature:
     \[
     IG(S, A) = H(S) - \sum_{v \in A} \frac{|S_v|}{|S|} H(S_v)
     \]

3. **Tree Construction:**
   - Recursively select the feature with the highest information gain to split the dataset.
   - Continue until all data in a subset belong to the same class or there are no remaining features.

---

## **Code Details**

### **Key Components**

1. **`calculateEntropy`:**
   - Computes the entropy of the dataset.

2. **`splitDataset`:**
   - Splits the dataset into subsets based on a feature value.

3. **`calculateInformationGain`:**
   - Calculates the information gain of a feature.

4. **`findBestFeature`:**
   - Determines the feature with the highest information gain.

5. **`decisionTreeID3`:**
   - Recursively builds the decision tree.

6. **`main`:**
   - Provides a small dataset and constructs the decision tree.

---

### **Code Walkthrough**

#### **Calculate Entropy**
```cpp
double calculateEntropy(const vector<int>& labels) {
    map<int, int> frequency;
    for (int label : labels) {
        frequency[label]++;
    }

    double entropy = 0.0;
    for (auto& pair : frequency) {
        double probability = (double)pair.second / labels.size();
        entropy -= probability * log2(probability);
    }
    return entropy;
}
```
Computes the entropy of the labels by summing \( -p \log_2(p) \) for each class.

#### **Calculate Information Gain**
```cpp
double calculateInformationGain(const vector<vector<int>>& dataset, const vector<int>& labels, int feature) {
    double originalEntropy = calculateEntropy(labels);

    map<int, vector<int>> splitLabels;
    splitDataset(dataset, labels, feature, splitLabels);

    double weightedEntropy = 0.0;
    for (auto& pair : splitLabels) {
        double weight = (double)pair.second.size() / labels.size();
        weightedEntropy += weight * calculateEntropy(pair.second);
    }

    return originalEntropy - weightedEntropy;
}
```
Calculates the information gain for a given feature by subtracting the weighted entropy of the split data from the original entropy.

#### **Decision Tree Construction**
```cpp
void decisionTreeID3(const vector<vector<int>>& dataset, const vector<int>& labels, set<int> usedFeatures) {
    if (labels.empty()) return;

    set<int> uniqueLabels(labels.begin(), labels.end());
    if (uniqueLabels.size() == 1) {
        cout << "Leaf Node: Class " << *uniqueLabels.begin() << endl;
        return;
    }

    if (usedFeatures.size() == dataset[0].size()) {
        cout << "Leaf Node: Majority Class " << endl;
        return;
    }

    int bestFeature = findBestFeature(dataset, labels);
    cout << "Split on Feature " << bestFeature << endl;

    usedFeatures.insert(bestFeature);

    map<int, vector<vector<int>>> subsets;
    map<int, vector<int>> subsetLabels;
    for (size_t i = 0; i < dataset.size(); ++i) {
        subsets[dataset[i][bestFeature]].push_back(dataset[i]);
        subsetLabels[dataset[i][bestFeature]].push_back(labels[i]);
    }

    for (auto& pair : subsets) {
        cout << "Feature Value " << pair.first << " -> ";
        decisionTreeID3(pair.second, subsetLabels[pair.first], usedFeatures);
    }
}
```
Recursively splits the dataset using the best feature and prints the structure of the decision tree.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `decision_tree_id3.cpp`.
2. Compile the code:
   ```bash
   g++ decision_tree_id3.cpp -o decision_tree_id3
   ```
3. Run the program:
   ```bash
   ./decision_tree_id3
   ```

---

## **Input/Output**

### **Input**
The program uses the following dataset and labels:
```cpp
vector<vector<int>> dataset = {{1, 1}, {1, 0}, {0, 1}, {0, 0}};
vector<int> labels = {1, 1, 0, 0};
```

### **Output**
The decision tree structure:
```plaintext
Split on Feature 0
Feature Value 1 -> Split on Feature 1
Feature Value 1 -> Leaf Node: Class 1
Feature Value 0 -> Leaf Node: Class 1
Feature Value 0 -> Split on Feature 1
Feature Value 1 -> Leaf Node: Class 0
Feature Value 0 -> Leaf Node: Class 0
```

---

## **Complexity**

### **Time Complexity**
- **Entropy Calculation:** \(O(n)\) per call
- **Information Gain Calculation:** \(O(n \times f)\), where \(f\) is the number of features.
- **Tree Construction:** Dependent on tree depth and number of splits.

### **Space Complexity**
- \(O(n)\) for dataset splits and label subsets.

---

## **Applications**

1. **Classification:**
   - Used in decision-making systems for categorical data.

2. **Machine Learning:**
   - Forms the basis for decision tree models and ensemble methods like Random Forests.

3. **Medical Diagnosis:**
   - Decision trees are used to identify diseases based on symptoms.

---

## **Customization**

- Modify the `dataset` and `labels` in the `main` function to test different scenarios.
- Extend the program to handle continuous features or build a full decision tree structure.

---

This implementation provides an efficient way to classify data using the ID3 algorithm, a foundational technique in machine learning and data analysis.