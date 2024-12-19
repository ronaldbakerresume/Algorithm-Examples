#include <iostream>
using namespace std;

const int PRIME = 101;

int createHash(const string& str, int end) {
    int hash = 0;
    for (int i = 0; i < end; ++i) {
        hash += str[i] * pow(PRIME, i);
    }
    return hash;
}

int recalculateHash(const string& str, int oldIndex, int newIndex, int oldHash, int patternLen) {
    oldHash -= str[oldIndex];
    oldHash /= PRIME;
    oldHash += str[newIndex] * pow(PRIME, patternLen - 1);
    return oldHash;
}

bool checkEquality(const string& str1, int start1, int end1, const string& str2) {
    if (end1 - start1 + 1 != str2.size()) return false;
    for (int i = start1; i <= end1; ++i) {
        if (str1[i] != str2[i - start1]) return false;
    }
    return true;
}

void rabinKarp(const string& text, const string& pattern) {
    int m = pattern.size(), n = text.size();
    int patternHash = createHash(pattern, m);
    int textHash = createHash(text, m);

    for (int i = 0; i <= n - m; ++i) {
        if (patternHash == textHash && checkEquality(text, i, i + m - 1, pattern)) {
            cout << "Pattern found at index " << i << endl;
        }
        if (i < n - m) {
            textHash = recalculateHash(text, i, i + m, textHash, m);
        }
    }
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";

    rabinKarp(text, pattern);
    return 0;
}

