/*
 * [857] Positions of Large Groups
 *
 * https://leetcode.com/problems/positions-of-large-groups/description/
 *
 * algorithms
 * Easy (46.21%)
 * Total Accepted:    16.1K
 * Total Submissions: 35K
 * Testcase Example:  '"abbxxxxzzy"'
 *
 * In a string S of lowercase letters, these letters form consecutive groups of
 * the same character.
 *
 * For example, a string like S = "abbxxxxzyy" has the groups "a", "bb",
 * "xxxx", "z" and "yy".
 *
 * Call a group large if it has 3 or more characters.  We would like the
 * starting and ending positions of every large group.
 *
 * The final answer should be in lexicographic order.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "abbxxxxzzy"
 * Output: [[3,6]]
 * Explanation: "xxxx" is the single large group with starting  3 and ending
 * positions 6.
 *
 *
 * Example 2:
 *
 *
 * Input: "abc"
 * Output: []
 * Explanation: We have "a","b" and "c" but no large group.
 *
 *
 * Example 3:
 *
 *
 * Input: "abcdddeeeeaabbbcd"
 * Output: [[3,5],[6,9],[12,14]]
 *
 *
 *
 * Note:  1 <= S.length <= 1000
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector< vector<int> > largeGroupPositions(string S) {
        vector< vector<int> > ret_vec;
        if (S.length() <= 2)
            return ret_vec;
        for (int i = 0; i < S.length() - 2;) {
            if (S[i] == S[i + 2]) {
                int pos = i + 3;
                while (pos < S.length() && S[pos] == S[i])
                    pos++;
                vector<int> group;
                group.push_back(i);
                group.push_back(pos - 1);
                cout << i << ", " << pos - 1 << endl;
                ret_vec.push_back(group);
                i = pos;
            } else {
                i++;
            }
        }

        return ret_vec;
    }
};

int main() {
    string A = "abcdddeeeeaabbbcd";
    class Solution B;
    //B.largeGroupPositions(A);
    B.largeGroupPositions("aba");
    return 0;
}
