/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (27.53%)
 * Total Accepted:    210.8K
 * Total Submissions: 765.7K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string *string_arr = new string[numRows];

        int row = 0;
        int step = 1;

        for (int i = 0; i < s.size(); i++) {
            string_arr[row].push_back(s[i]);
            if (numRows == 1)
                row = 0;
            else {
                if (row == numRows - 1)
                    step = -1;
                else if (row == 0)
                    step = 1;
                row += step;
            }
        }
        s.clear();
        for (int i = 0; i < numRows; i++) {
            s.append(string_arr[i]);
        }
        return s;
    }
};

int main() {
    Solution A;
    cout << A.convert("PAYPALISHIRING", 3) << endl;
    cout << A.convert("PAYPALISHIRING", 4) << endl;
    cout << A.convert("AB", 1) << endl;
}
