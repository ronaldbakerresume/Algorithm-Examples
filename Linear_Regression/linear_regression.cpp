#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

pair<double, double> linearRegression(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double intercept = (sumY - slope * sumX) / n;

    return {slope, intercept};
}

int main() {
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2, 4, 5, 4, 5};

    auto [slope, intercept] = linearRegression(x, y);
    cout << "Linear Regression: y = " << slope << "x + " << intercept << endl;

    double predictX = 6.0;
    cout << "Prediction for x = " << predictX << ": y = " << slope * predictX + intercept << endl;

    return 0;
}

