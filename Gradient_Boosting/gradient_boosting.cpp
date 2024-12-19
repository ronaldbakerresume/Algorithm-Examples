#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double computeResidual(const vector<double>& predictions, const vector<double>& actual, int index) {
    return actual[index] - predictions[index];
}

void gradientBoosting(const vector<double>& x, const vector<double>& y, int numIterations, double learningRate) {
    int n = x.size();
    vector<double> predictions(n, 0.0);

    for (int iteration = 0; iteration < numIterations; ++iteration) {
        vector<double> residuals(n);

        // Compute residuals
        for (int i = 0; i < n; ++i) {
            residuals[i] = computeResidual(predictions, y, i);
        }

        // Fit a simple regression tree (in this case, a single constant value)
        double meanResidual = 0.0;
        for (int i = 0; i < n; ++i) {
            meanResidual += residuals[i];
        }
        meanResidual /= n;

        // Update predictions
        for (int i = 0; i < n; ++i) {
            predictions[i] += learningRate * meanResidual;
        }

        // Compute loss
        double loss = 0.0;
        for (int i = 0; i < n; ++i) {
            loss += pow(predictions[i] - y[i], 2);
        }
        loss /= n;

        cout << "Iteration " << iteration + 1 << ": Loss = " << loss << endl;
    }

    cout << "Final predictions: ";
    for (double pred : predictions) {
        cout << pred << " ";
    }
    cout << endl;
}

int main() {
    vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<double> y = {1.5, 3.0, 4.5, 6.0, 7.5};

    int numIterations = 10;
    double learningRate = 0.1;

    gradientBoosting(x, y, numIterations, learningRate);
    return 0;
}

