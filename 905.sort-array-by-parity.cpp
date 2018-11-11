/*
 * [941] Sort Array By Parity
 *
 * https://leetcode.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (70.58%)
 * Total Accepted:    28.3K
 * Total Submissions: 40K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array A of non-negative integers, return an array consisting of all
 * the even elements of A, followed by all the odd elements of A.
 *
 * You may return any answer array that satisfies this condition.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 *
 *
 *
 */
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int begin = 0;
        int end = A.size() - 1;
        int tmp;
        while (begin < end) {
            if (A[end] % 2 == 0) {
                if (A[begin] % 2 == 1) {
                    tmp = A[end];
                    A[end] = A[begin];
                    A[begin] = tmp;
                    end--;
                    begin++;
                } else {
                    begin++;
                }
            } else {
                end--;
            }
        }
        return A;
    }
};
