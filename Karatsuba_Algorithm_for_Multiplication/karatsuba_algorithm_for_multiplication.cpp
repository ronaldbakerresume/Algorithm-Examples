#include <iostream>
#include <string>
using namespace std;

int makeEqualLength(string& str1, string& str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2) {
        str1.insert(0, len2 - len1, '0');
    } else if (len2 < len1) {
        str2.insert(0, len1 - len2, '0');
    }
    return str1.size();
}

string addStrings(const string& num1, const string& num2) {
    string result;
    int carry = 0, sum;
    for (int i = num1.size() - 1; i >= 0; i--) {
        sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        result.insert(result.begin(), sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry) result.insert(result.begin(), carry + '0');
    return result;
}

string multiplySingleDigit(const string& num1, char digit) {
    string result;
    int carry = 0, product;
    for (int i = num1.size() - 1; i >= 0; i--) {
        product = (num1[i] - '0') * (digit - '0') + carry;
        result.insert(result.begin(), product % 10 + '0');
        carry = product / 10;
    }
    if (carry) result.insert(result.begin(), carry + '0');
    return result;
}

string multiplyStrings(const string& num1, const string& num2) {
    if (num1 == "0" || num2 == "0") return "0";
    string result = "0";
    for (int i = num2.size() - 1; i >= 0; i--) {
        string temp = multiplySingleDigit(num1, num2[i]);
        temp.append(num2.size() - 1 - i, '0');
        result = addStrings(result, temp);
    }
    return result;
}

int karatsubaMultiply(int x, int y) {
    string strX = to_string(x);
    string strY = to_string(y);
    int n = makeEqualLength(strX, strY);

    if (n == 1) return x * y;

    int mid = n / 2;
    int a = stoi(strX.substr(0, mid));
    int b = stoi(strX.substr(mid));
    int c = stoi(strY.substr(0, mid));
    int d = stoi(strY.substr(mid));

    int ac = karatsubaMultiply(a, c);
    int bd = karatsubaMultiply(b, d);
    int adbc = karatsubaMultiply(a + b, c + d) - ac - bd;

    return ac * pow(10, n) + adbc * pow(10, n / 2) + bd;
}

int main() {
    int x = 1234, y = 5678;
    cout << "Karatsuba Multiplication: " << karatsubaMultiply(x, y) << endl;
    return 0;
}

