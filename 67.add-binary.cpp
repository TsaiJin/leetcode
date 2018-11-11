/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (35.64%)
 * Total Accepted:    242K
 * Total Submissions: 668.8K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 */
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() == 0)
            return b;
        if (b.length() == 0)
            return a;
        if (a.length() > b.length()) {
            string all_zero_str(a.length() - b.length(), '0');
            b.insert(0, all_zero_str);
        } else if (b.length() > a.length()) {
            string all_zero_str(b.length() - a.length(), '0');
            a.insert(0, all_zero_str);
        }

        int a_len = a.length() - 1;
        int b_len = b.length() - 1;
        int pos = 0;
        int a_binary_val, b_binary_val, increment = 0;
        string result_str = "";
        for (int pos = a_len; pos >= 0; pos--) {
            a_binary_val = a[pos] - '0';
            b_binary_val = b[pos] - '0';
            if (a_binary_val + b_binary_val + increment >= 2) {
                result_str += ('0' + (a_binary_val + b_binary_val + increment - 2));
                increment = 1;
            } else {
                result_str += ('0' + a_binary_val + b_binary_val + increment);
                increment = 0;
            }
        }

        if (increment)
            result_str += '0' + increment;

        reverse(result_str.begin(), result_str.end());
        return result_str;
    }
};

int main() {
    Solution A;
    cout << A.addBinary("1111", "1111");
    return 0;
}
