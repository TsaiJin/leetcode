/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (37.82%)
 * Total Accepted:    219.2K
 * Total Submissions: 579.4K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 *
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 *
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: "1"
 *
 *
 * Example 2:
 *
 *
 * Input: 4
 * Output: "1211"
 *
 */

//#include <queue>
//#include <iostream>
//#include <string>
//using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        queue<int> queue_1, queue_2;
        int current_cmp_val, same_count;
        queue_1.push(1);
        string final_result = "";
        if (n == 1)
            return "1";
        for (int i = 2; i <= n; i++) {
            current_cmp_val = -1;
            same_count = 0;
            while (!queue_1.empty()) {
                if (current_cmp_val != queue_1.front()) {
                    if (current_cmp_val == -1) {
                        same_count = 1;
                    } else {
                        queue_2.push(same_count);
                        queue_2.push(current_cmp_val);
                        same_count = 0;
                    }
                    current_cmp_val = queue_1.front();
                    same_count = 1;
                    queue_1.pop();
                    if (queue_1.empty()) {
                        queue_2.push(same_count);
                        queue_2.push(current_cmp_val);
                        break;
                    }
                } else {
                    same_count++;
                    queue_1.pop();
                    if (queue_1.empty()) {
                        queue_2.push(same_count);
                        queue_2.push(current_cmp_val);
                        break;
                    }
                }
            }
            queue_1.swap(queue_2);
        }
        int i = 0;
        while (!queue_1.empty()) {
            final_result += (char)(queue_1.front() + '0');
            i++;
            queue_1.pop();
        }
        return final_result;
    }
};

//int main() {
//    Solution s;
//}
