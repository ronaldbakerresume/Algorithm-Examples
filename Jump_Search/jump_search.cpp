#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int jumpSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    for (int i = prev; i < min(step, n); ++i) {
        if (arr[i] == target) return i;
    }

    return -1;
}

int main() {
    vector<int> arr = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    int target = 21;
    int index = jumpSearch(arr, target);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    return 0;
}

