#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) return i; // Return index of the target
    }
    return -1; // Return -1 if not found
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 30;
    int index = linearSearch(arr, target);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    return 0;
}

