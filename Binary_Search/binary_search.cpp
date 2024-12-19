#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid; // Target found
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Target not found
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 30;
    int index = binarySearch(arr, target);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    return 0;
}

