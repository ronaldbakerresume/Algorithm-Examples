#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
    double valuePerWeight;
};

bool compareItems(const Item& a, const Item& b) {
    return a.valuePerWeight > b.valuePerWeight;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compareItems);

    double maxValue = 0.0;
    for (const auto& item : items) {
        if (capacity >= item.weight) {
            maxValue += item.value;
            capacity -= item.weight;
        } else {
            maxValue += capacity * item.valuePerWeight;
            break;
        }
    }
    return maxValue;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    for (auto& item : items) {
        item.valuePerWeight = (double)item.value / item.weight;
    }

    int capacity = 50;
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(capacity, items) << endl;
    return 0;
}

