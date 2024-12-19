#include <iostream>
#include <cmath>
using namespace std;

double gradient(double x) {
    return 2 * x; // Gradient of the function f(x) = x^2
}

void gradientDescent(double initialX, double learningRate, int iterations) {
    double x = initialX;
    for (int i = 0; i < iterations; ++i) {
        double grad = gradient(x);
        x -= learningRate * grad; // Update x
        cout << "Iteration " << i + 1 << ": x = " << x << ", f(x) = " << x * x << endl;
    }
}

int main() {
    double initialX = 10.0;
    double learningRate = 0.1;
    int iterations = 20;
    gradientDescent(initialX, learningRate, iterations);
    return 0;
}

