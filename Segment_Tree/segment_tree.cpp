#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree, arr;
    int n;

    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(2 * node, start, mid);
            buildTree(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int queryTree(int node, int start, int end, int L, int R) {
        if (start > R || end < L) return 0;
        if (start >= L && end <= R) return tree[node];
        int mid = (start + end) / 2;
        int leftSum = queryTree(2 * node, start, mid, L, R);
        int rightSum = queryTree(2 * node + 1, mid + 1, end, L, R);
        return leftSum + rightSum;
    }

    void updateTree(int node, int start, int end, int index, int value) {
        if (start == end) {
            tree[node] = value;
            arr[index] = value;
        } else {
            int mid = (start + end) / 2;
            if (index >= start && index <= mid) {
                updateTree(2 * node, start, mid, index, value);
            } else {
                updateTree(2 * node + 1, mid + 1, end, index, value);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

public:
    SegmentTree(vector<int>& input) {
        n = input.size();
        arr = input;
        tree.resize(4 * n, 0);
        buildTree(1, 0, n - 1);
    }

    int query(int L, int R) {
        return queryTree(1, 0, n - 1, L, R);
    }

    void update(int index, int value) {
        updateTree(1, 0, n - 1, index, value);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    cout << "Sum of range [1, 3]: " << segTree.query(1, 3) << endl;
    segTree.update(1, 10);
    cout << "Sum of range [1, 3] after update: " << segTree.query(1, 3) << endl;

    return 0;
}

