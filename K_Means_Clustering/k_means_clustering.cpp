#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

double euclideanDistance(const vector<double>& a, const vector<double>& b) {
    double sum = 0.0;
    for (int i = 0; i < a.size(); ++i) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

void kMeans(vector<vector<double>>& data, int k, int iterations) {
    int n = data.size(), dim = data[0].size();
    vector<vector<double>> centroids(k, vector<double>(dim, 0));
    vector<int> labels(n, -1);

    // Initialize centroids randomly
    srand(time(0));
    for (int i = 0; i < k; ++i) {
        centroids[i] = data[rand() % n];
    }

    for (int iter = 0; iter < iterations; ++iter) {
        // Assign each point to the closest centroid
        for (int i = 0; i < n; ++i) {
            double minDist = 1e9;
            for (int j = 0; j < k; ++j) {
                double dist = euclideanDistance(data[i], centroids[j]);
                if (dist < minDist) {
                    minDist = dist;
                    labels[i] = j;
                }
            }
        }

        // Update centroids
        vector<vector<double>> newCentroids(k, vector<double>(dim, 0));
        vector<int> counts(k, 0);
        for (int i = 0; i < n; ++i) {
            for (int d = 0; d < dim; ++d) {
                newCentroids[labels[i]][d] += data[i][d];
            }
            counts[labels[i]]++;
        }
        for (int j = 0; j < k; ++j) {
            if (counts[j] > 0) {
                for (int d = 0; d < dim; ++d) {
                    newCentroids[j][d] /= counts[j];
                }
            }
        }
        centroids = newCentroids;
    }

    // Output clusters
    cout << "Final Clusters:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Point " << i + 1 << " belongs to cluster " << labels[i] + 1 << endl;
    }
}

int main() {
    vector<vector<double>> data = {{1.0, 1.0}, {1.5, 2.0}, {3.0, 4.0}, {5.0, 7.0}, {3.5, 5.0}, {4.5, 5.0}, {3.5, 4.5}};
    int k = 2, iterations = 10;

    kMeans(data, k, iterations);
    return 0;
}

