#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> bit;
    int size;

public:
    FenwickTree(int n) {
        size = n + 1;
        bit.assign(size, 0);
    }

    void update(int index, int value) {
        for (; index < size; index += index & -index) {
            bit[index] += value;
        }
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index) {
            sum += bit[index];
        }
        return sum;
    }

    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    FenwickTree fenwick(10);
    fenwick.update(1, 5);
    fenwick.update(4, 7);
    fenwick.update(7, 3);

    cout << "Sum of range [1, 4]: " << fenwick.rangeQuery(1, 4) << endl;
    cout << "Sum of range [1, 7]: " << fenwick.rangeQuery(1, 7) << endl;
    return 0;
}

