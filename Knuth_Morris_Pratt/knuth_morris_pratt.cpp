#include <iostream>
#include <vector>
using namespace std;

void computeLPSArray(const string& pattern, vector<int>& lps) {
    int length = 0, i = 1;
    lps[0] = 0;

    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            lps[i++] = ++length;
        } else if (length != 0) {
            length = lps[length - 1];
        } else {
            lps[i++] = 0;
        }
    }
}

void KMP(const string& text, const string& pattern) {
    int m = pattern.size(), n = text.size();
    vector<int> lps(m, 0);

    computeLPSArray(pattern, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++, j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            j ? j = lps[j - 1] : i++;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    KMP(text, pattern);
    return 0;
}

