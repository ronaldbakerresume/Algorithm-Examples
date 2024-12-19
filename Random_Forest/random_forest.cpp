#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<vector<int>> sampleDataset(const vector<vector<int>>& dataset, const vector<int>& labels,
                                  vector<int>& sampledLabels, int numSamples) {
    vector<vector<int>> sampledDataset;
    sampledLabels.clear();
    srand(time(0));
    for (int i = 0; i < numSamples; ++i) {
        int idx = rand() % dataset.size();
        sampledDataset.push_back(dataset[idx]);
        sampledLabels.push_back(labels[idx]);
    }
    return sampledDataset;
}

void randomForest(const vector<vector<int>>& dataset, const vector<int>& labels, int numTrees) {
    vector<vector<vector<int>>> trees;

    for (int t = 0; t < numTrees; ++t) {
        vector<int> sampledLabels;
        vector<vector<int>> sampledDataset = sampleDataset(dataset, labels, sampledLabels, dataset.size());

        cout << "Tree " << t + 1 << ":" << endl;
        set<int> usedFeatures;
        decisionTreeID3(sampledDataset, sampledLabels, usedFeatures);
        cout << endl;
    }
}

int main() {
    vector<vector<int>> dataset = {{1, 1}, {1, 0}, {0, 1}, {0, 0}};
    vector<int> labels = {1, 1, 0, 0};

    int numTrees = 3;
    randomForest(dataset, labels, numTrees);

    return 0;
}

