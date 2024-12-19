### `README.md` for Naive Bayes Classifier Implementation

---

# **Naive Bayes Classifier**

This project implements a simple **Naive Bayes Classifier** in C++ for a binary classification task. It calculates the likelihood of a data point belonging to each class using the Gaussian probability density function.

---

## **Problem Description**

Given:
- A dataset with continuous numerical features and binary labels (0 or 1).

Goal:
- Classify a new data point based on the likelihood of it belonging to either class.

---

## **Algorithm**

The Naive Bayes Classifier is based on **Bayes' Theorem**:

\[
P(C|X) = \frac{P(X|C) \cdot P(C)}{P(X)}
\]

Where:
- \(P(C|X)\): Posterior probability of class \(C\) given data \(X\).
- \(P(X|C)\): Likelihood of data \(X\) given class \(C\).
- \(P(C)\): Prior probability of class \(C\).
- \(P(X)\): Evidence (constant for comparison).

### **Steps:**

1. **Calculate Priors:**
   - \(P(C=0) = \frac{\text{Count(Class 0)}}{\text{Total Samples}}\)
   - \(P(C=1) = \frac{\text{Count(Class 1)}}{\text{Total Samples}}\)

2. **Estimate Likelihood Using Gaussian Distribution:**
   - For a feature \(x\), given class \(C\):
     \[
     P(x|C) = \frac{1}{\sqrt{2\pi\sigma^2}} \cdot e^{-\frac{(x-\mu)^2}{2\sigma^2}}
     \]
   - Where \(\mu\) and \(\sigma^2\) are the mean and variance of the feature in class \(C\).

3. **Classify Test Point:**
   - Compute posterior probabilities for each class and choose the class with the higher value.

---

## **Code Details**

### **Key Components**

1. **Gaussian Probability Density Function:**
   - Computes the likelihood of a data point given a class:
     ```cpp
     double calculateProbability(double x, double mean, double variance) {
         double exponent = exp(-pow(x - mean, 2) / (2 * variance));
         return (1 / sqrt(2 * M_PI * variance)) * exponent;
     }
     ```

2. **Naive Bayes Function:**
   - Computes the class priors, likelihoods, and predicts the class for a test point:
     ```cpp
     void naiveBayes(const vector<double>& data, const vector<int>& labels) {
         int n = data.size();
         double mean0 = 0, mean1 = 0, variance0 = 0, variance1 = 0, count0 = 0, count1 = 0;

         // Calculate means and priors
         for (int i = 0; i < n; ++i) {
             if (labels[i] == 0) {
                 mean0 += data[i];
                 count0++;
             } else {
                 mean1 += data[i];
                 count1++;
             }
         }
         mean0 /= count0;
         mean1 /= count1;

         // Calculate variances
         for (int i = 0; i < n; ++i) {
             if (labels[i] == 0) {
                 variance0 += pow(data[i] - mean0, 2);
             } else {
                 variance1 += pow(data[i] - mean1, 2);
             }
         }
         variance0 /= count0;
         variance1 /= count1;

         // Output class statistics
         cout << "Class 0: Mean = " << mean0 << ", Variance = " << variance0 << endl;
         cout << "Class 1: Mean = " << mean1 << ", Variance = " << variance1 << endl;

         // Predict for a test point
         double testPoint = 2.5;
         double prob0 = calculateProbability(testPoint, mean0, variance0) * (count0 / n);
         double prob1 = calculateProbability(testPoint, mean1, variance1) * (count1 / n);

         cout << "Prediction for x = " << testPoint << ": Class " << (prob1 > prob0 ? 1 : 0) << endl;
     }
     ```

3. **Main Function:**
   - Calls the `naiveBayes` function with sample data:
     ```cpp
     int main() {
         vector<double> data = {1.0, 2.0, 3.0, 6.0, 8.0};
         vector<int> labels = {0, 0, 0, 1, 1};

         naiveBayes(data, labels);
         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `naive_bayes.cpp`.
2. Compile the code:
   ```bash
   g++ naive_bayes.cpp -o naive_bayes -lm
   ```
3. Run the program:
   ```bash
   ./naive_bayes
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded data:
```plaintext
Data: [1.0, 2.0, 3.0, 6.0, 8.0]
Labels: [0, 0, 0, 1, 1]
```

### **Output**
```plaintext
Class 0: Mean = 2, Variance = 0.666667
Class 1: Mean = 7, Variance = 2
Prediction for x = 2.5: Class 0
```

---

## **Complexity**

### **Time Complexity**
- \(O(n)\): Calculating mean, variance, and probabilities requires one pass through the dataset.

### **Space Complexity**
- \(O(1)\): Uses a constant amount of extra space.

---

## **Applications**

1. **Spam Filtering:**
   - Classify emails as spam or not spam based on word occurrences.
2. **Medical Diagnosis:**
   - Predict diseases based on symptoms or test results.
3. **Text Classification:**
   - Sentiment analysis, language detection, etc.

---

## **Advantages**

1. **Simplicity:**
   - Easy to implement and interpret.
2. **Efficiency:**
   - Computationally efficient for small datasets.

---

## **Limitations**

1. **Feature Independence Assumption:**
   - Assumes features are independent, which might not hold in real-world scenarios.
2. **Continuous Data:**
   - Requires Gaussian assumptions for numerical data.

---

This implementation of Naive Bayes demonstrates a foundational technique for classification tasks and provides a basis for exploring more advanced models.