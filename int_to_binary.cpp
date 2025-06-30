// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Convert integer to binary string of length k
string intToBinary(int num, int k) {
    string res;
    for (int i = k - 1; i >= 0; --i)
        res += ((num >> i) & 1) ? '1' : '0';
    return res;
}

bool hasAllCodes(string s, int k) {
    int total = 1 << k; // 2^k
    for (int i = 0; i < total; ++i) {
        string code = intToBinary(i, k);
        if (s.find(code) == string::npos) // not found
            return false;
    }
    return true;
}

int main() {
    cout << boolalpha;
    cout << hasAllCodes("00110110", 2) << endl; // true
    cout << hasAllCodes("0110", 1) << endl;     // true
    cout << hasAllCodes("0110", 2) << endl;     // false
    return 0;
}
