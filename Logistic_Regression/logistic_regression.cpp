#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

double logisticLoss(const vector<double>& x, const vector<int>& y, double w, double b) {
    double loss = 0.0;
    for (int i = 0; i < x.size(); ++i) {
        double prediction = sigmoid(w * x[i] + b);
        loss += -y[i] * log(prediction) - (1 - y[i]) * log(1 - prediction);
    }
    return loss / x.size();
}

void logisticRegression(const vector<double>& x, const vector<int>& y, double& w, double& b, double lr, int epochs) {
    int n = x.size();

    for (int epoch = 0; epoch < epochs; ++epoch) {
        double dw = 0.0, db = 0.0;

        for (int i = 0; i < n; ++i) {
            double prediction = sigmoid(w * x[i] + b);
            dw += (prediction - y[i]) * x[i];
            db += (prediction - y[i]);
        }

        w -= lr * dw / n;
        b -= lr * db / n;

        if (epoch % 100 == 0) {
            cout << "Epoch " << epoch << ", Loss: " << logisticLoss(x, y, w, b) << endl;
        }
    }
}

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

