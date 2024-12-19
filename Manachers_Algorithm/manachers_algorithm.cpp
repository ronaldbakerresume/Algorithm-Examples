#include <iostream>
#include <vector>
using namespace std;

string preprocess(const string& s) {
    string t = "^";
    for (char c : s) {
        t += "#" + string(1, c);
    }
    t += "#$";
    return t;
}

string longestPalindrome(const string& s) {
    string t = preprocess(s);
    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;

    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * center - i;

        if (i < right) p[i] = min(right - i, p[mirror]);

        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    int maxLen = 0, centerIdx = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIdx = i;
        }
    }

    int start = (centerIdx - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string s = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}

