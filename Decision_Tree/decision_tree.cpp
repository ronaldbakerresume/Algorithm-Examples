#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;

// Function to calculate entropy
double calculateEntropy(const vector<int>& labels) {
    map<int, int> frequency;
    for (int label : labels) {
        frequency[label]++;
    }

    double entropy = 0.0;
    for (auto& pair : frequency) {
        double probability = (double)pair.second / labels.size();
        entropy -= probability * log2(probability);
    }
    return entropy;
}

// Split dataset based on a feature
void splitDataset(const vector<vector<int>>& dataset, const vector<int>& labels, int feature,
                  map<int, vector<int>>& splitLabels) {
    for (size_t i = 0; i < dataset.size(); ++i) {
        splitLabels[dataset[i][feature]].push_back(labels[i]);
    }
}

// Function to calculate information gain
double calculateInformationGain(const vector<vector<int>>& dataset, const vector<int>& labels, int feature) {
    double originalEntropy = calculateEntropy(labels);

    map<int, vector<int>> splitLabels;
    splitDataset(dataset, labels, feature, splitLabels);

    double weightedEntropy = 0.0;
    for (auto& pair : splitLabels) {
        double weight = (double)pair.second.size() / labels.size();
        weightedEntropy += weight * calculateEntropy(pair.second);
    }

    return originalEntropy - weightedEntropy;
}

int findBestFeature(const vector<vector<int>>& dataset, const vector<int>& labels) {
    double maxGain = -1.0;
    int bestFeature = -1;

    for (size_t feature = 0; feature < dataset[0].size(); ++feature) {
        double gain = calculateInformationGain(dataset, labels, feature);
        if (gain > maxGain) {
            maxGain = gain;
            bestFeature = feature;
        }
    }
    return bestFeature;
}

void decisionTreeID3(const vector<vector<int>>& dataset, const vector<int>& labels, set<int> usedFeatures) {
    if (labels.empty()) return;

    // Check if all labels are the same
    set<int> uniqueLabels(labels.begin(), labels.end());
    if (uniqueLabels.size() == 1) {
        cout << "Leaf Node: Class " << *uniqueLabels.begin() << endl;
        return;
    }

    // Check if there are no remaining features to split
    if (usedFeatures.size() == dataset[0].size()) {
        cout << "Leaf Node: Majority Class " << endl;
        return;
    }

    // Find the best feature to split on
    int bestFeature = findBestFeature(dataset, labels);
    cout << "Split on Feature " << bestFeature << endl;

    usedFeatures.insert(bestFeature);

    // Split dataset and recurse
    map<int, vector<vector<int>>> subsets;
    map<int, vector<int>> subsetLabels;
    for (size_t i = 0; i < dataset.size(); ++i) {
        subsets[dataset[i][bestFeature]].push_back(dataset[i]);
        subsetLabels[dataset[i][bestFeature]].push_back(labels[i]);
    }

    for (auto& pair : subsets) {
        cout << "Feature Value " << pair.first << " -> ";
        decisionTreeID3(pair.second, subsetLabels[pair.first], usedFeatures);
    }
}

int main() {
    vector<vector<int>> dataset = {{1, 1}, {1, 0}, {0, 1}, {0, 0}};
    vector<int> labels = {1, 1, 0, 0};

    set<int> usedFeatures;
    decisionTreeID3(dataset, labels, usedFeatures);
    return 0;
}

