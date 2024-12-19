#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double monteCarloPi(int iterations) {
    int insideCircle = 0;
    for (int i = 0; i < iterations; ++i) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            insideCircle++;
        }
    }
    return 4.0 * insideCircle / iterations;
}

int main() {
    int iterations = 1000000;
    cout << "Estimated Pi: " << monteCarloPi(iterations) << endl;
    return 0;
}

