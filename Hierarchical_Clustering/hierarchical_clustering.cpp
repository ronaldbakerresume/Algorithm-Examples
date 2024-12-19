#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

double euclideanDistance(const vector<double>& a, const vector<double>& b) {
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

int findMinDistanceCluster(const vector<vector<double>>& distances, const set<int>& activeClusters) {
    double minDist = 1e9;
    pair<int, int> minPair;

    for (int i : activeClusters) {
        for (int j : activeClusters) {
            if (i != j && distances[i][j] < minDist) {
                minDist = distances[i][j];
                minPair = {i, j};
            }
        }
    }

    return minPair.first * distances.size() + minPair.second; // Encode pair into single int
}

void hierarchicalClustering(vector<vector<double>>& points) {
    int n = points.size();
    vector<vector<double>> distances(n, vector<double>(n));

    // Compute initial distances
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            distances[i][j] = euclideanDistance(points[i], points[j]);
        }
    }

    set<int> activeClusters;
    for (int i = 0; i < n; ++i) {
        activeClusters.insert(i);
    }

    while (activeClusters.size() > 1) {
        int pairEncoded = findMinDistanceCluster(distances, activeClusters);
        int clusterA = pairEncoded / n, clusterB = pairEncoded % n;

        // Merge clusters
        cout << "Merging cluster " << clusterA << " with cluster " << clusterB << endl;
        activeClusters.erase(clusterB);

        // Update distances
        for (int i : activeClusters) {
            if (i != clusterA) {
                distances[clusterA][i] = distances[i][clusterA] = 
                    (distances[clusterA][i] + distances[clusterB][i]) / 2;
            }
        }
    }
}

int main() {
    vector<vector<double>> points = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {8.0, 9.0}};
    hierarchicalClustering(points);
    return 0;
}

