#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double calculateProbability(double x, double mean, double variance) {
    double exponent = exp(-pow(x - mean, 2) / (2 * variance));
    return (1 / sqrt(2 * M_PI * variance)) * exponent;
}

void naiveBayes(const vector<double>& data, const vector<int>& labels) {
    int n = data.size();
    double mean0 = 0, mean1 = 0, variance0 = 0, variance1 = 0, count0 = 0, count1 = 0;

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

    for (int i = 0; i < n; ++i) {
        if (labels[i] == 0) {
            variance0 += pow(data[i] - mean0, 2);
        } else {
            variance1 += pow(data[i] - mean1, 2);
        }
    }
    variance0 /= count0;
    variance1 /= count1;

    cout << "Class 0: Mean = " << mean0 << ", Variance = " << variance0 << endl;
    cout << "Class 1: Mean = " << mean1 << ", Variance = " << variance1 << endl;

    double testPoint = 2.5;
    double prob0 = calculateProbability(testPoint, mean0, variance0) * (count0 / n);
    double prob1 = calculateProbability(testPoint, mean1, variance1) * (count1 / n);

    cout << "Prediction for x = " << testPoint << ": Class " << (prob1 > prob0 ? 1 : 0) << endl;
}

int main() {
    vector<double> data = {1.0, 2.0, 3.0, 6.0, 8.0};
    vector<int> labels = {0, 0, 0, 1, 1};

    naiveBayes(data, labels);
    return 0;
}

