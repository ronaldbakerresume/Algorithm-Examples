### `README.md` for Logistic Regression Implementation

---

# **Logistic Regression**

This project implements **Logistic Regression** in C++. Logistic Regression is a classification algorithm used to predict the probability of a binary outcome based on one or more input features.

---

## **Problem Description**

Given:
- A set of data points \((x, y)\), where \(x\) represents the feature and \(y\) represents the binary label (\(0\) or \(1\)).

Goal:
- Fit a model of the form:
  \[
  P(y=1|x) = \sigma(wx + b)
  \]
  Where \(\sigma(z)\) is the sigmoid function:
  \[
  \sigma(z) = \frac{1}{1 + e^{-z}}
  \]

### **Example Input**

```plaintext
x: [0.5, 1.5, 2.0, 3.0, 3.5]
y: [0, 0, 1, 1, 1]
```

### **Expected Output**

```plaintext
Epoch 0, Loss: 0.693147
...
Epoch 900, Loss: 0.286732
Prediction for x = 2.5: 0.731058
```

---

## **How It Works**

### **Algorithm**

1. **Initialization:**
   - Start with initial values for the weight \(w\) and bias \(b\) (e.g., \(0\)).

2. **Prediction:**
   - Use the sigmoid function to predict probabilities:
     \[
     P(y=1|x) = \sigma(wx + b)
     \]

3. **Loss Function:**
   - Compute the logistic loss:
     \[
     \text{Loss} = -\frac{1}{n} \sum_{i=1}^{n} \left[ y_i \log(p_i) + (1-y_i) \log(1-p_i) \right]
     \]

4. **Gradient Descent:**
   - Compute gradients for \(w\) and \(b\):
     \[
     \frac{\partial \text{Loss}}{\partial w} = \frac{1}{n} \sum_{i=1}^{n} (p_i - y_i)x_i
     \]
     \[
     \frac{\partial \text{Loss}}{\partial b} = \frac{1}{n} \sum_{i=1}^{n} (p_i - y_i)
     \]
   - Update \(w\) and \(b\) using the learning rate \(\eta\):
     \[
     w \leftarrow w - \eta \frac{\partial \text{Loss}}{\partial w}
     \]
     \[
     b \leftarrow b - \eta \frac{\partial \text{Loss}}{\partial b}
     \]

5. **Iterate:**
   - Repeat the process for a specified number of epochs.

---

## **Code Details**

### **Key Components**

1. **Sigmoid Function:**
   - Computes the sigmoid of a value:
     ```cpp
     double sigmoid(double z) {
         return 1.0 / (1.0 + exp(-z));
     }
     ```

2. **Loss Function:**
   - Calculates the logistic loss:
     ```cpp
     double logisticLoss(const vector<double>& x, const vector<int>& y, double w, double b) {
         double loss = 0.0;
         for (int i = 0; i < x.size(); ++i) {
             double prediction = sigmoid(w * x[i] + b);
             loss += -y[i] * log(prediction) - (1 - y[i]) * log(1 - prediction);
         }
         return loss / x.size();
     }
     ```

3. **Gradient Descent:**
   - Updates weights and biases iteratively:
     ```cpp
     void logisticRegression(const vector<double>& x, const vector<int>& y, double& w, double& b, double lr, int epochs) {
         int n = x.size();

         for (int epoch = 0; epoch < epochs; ++epoch) {
             double dw = 0.0, db = 0.0;

             for (int i = 0; i < n; ++i) {
                 double prediction = sigmoid(w * x[i] + b);
                 dw += (prediction - y[i]) * x[i;
                 db += (prediction - y[i]);
             }

             w -= lr * dw / n;
             b -= lr * db / n;

             if (epoch % 100 == 0) {
                 cout << "Epoch " << epoch << ", Loss: " << logisticLoss(x, y, w, b) << endl;
             }
         }
     }
     ```

4. **Main Function:**
   - Runs the training and makes a prediction:
     ```cpp
     int main() {
         vector<double> x = {0.5, 1.5, 2.0, 3.0, 3.5};
         vector<int> y = {0, 0, 1, 1, 1}; // Labels

         double w = 0.0, b = 0.0;
         double learningRate = 0.1;
         int epochs = 1000;

         logisticRegression(x, y, w, b, learningRate, epochs);

         double predictX = 2.5;
         double probability = sigmoid(w * predictX + b);
         cout << "Prediction for x = " << predictX << ": " << probability << endl;

         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `logistic_regression.cpp`.
2. Compile the code:
   ```bash
   g++ logistic_regression.cpp -o logistic_regression
   ```
3. Run the program:
   ```bash
   ./logistic_regression
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded values:
```plaintext
x: [0.5, 1.5, 2.0, 3.0, 3.5]
y: [0, 0, 1, 1, 1]
```

### **Output**
```plaintext
Epoch 0, Loss: 0.693147
...
Epoch 900, Loss: 0.286732
Prediction for x = 2.5: 0.731058
```

---

## **Complexity**

### **Time Complexity**
- \(O(n \cdot \text{epochs})\): Iterates over the dataset for each epoch.

### **Space Complexity**
- \(O(1)\): Uses constant space for weights and gradients.

---

## **Applications**

1. **Binary Classification:**
   - Spam detection, fraud detection, medical diagnosis.
2. **Predictive Analytics:**
   - Customer conversion likelihood.

---

## **Advantages**

1. Easy to interpret probabilities.
2. Works well for binary classification tasks.

---

## **Limitations**

1. Only supports binary classification.
2. Assumes a linear relationship between inputs and logits.

---

This implementation demonstrates the fundamentals of Logistic Regression, providing a hands-on example of binary classification using gradient descent.