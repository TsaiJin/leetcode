/*
 * [958] Sort Array By Parity II
 *
 * https://leetcode.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (66.29%)
 * Total Accepted:    9.4K
 * Total Submissions: 14.2K
 * Testcase Example:  '[4,2,5,7]'
 *
 * Given an array A of non-negative integers, half of the integers in A are
 * odd, and half of the integers are even.
 *
 * Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is
 * even, i is even.
 *
 * You may return any answer array that satisfies this condition.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [4,2,5,7]
 * Output: [4,5,2,7]
 * Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been
 * accepted.
 *
 *
 *
 *
 * Note:
 *
 *
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
 *
 *
 *
 *
 *
 *
 */
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int index = 0;
        int tmp;
        for (int i = 0; i < A.size() && index < A.size(); ) {
            if (A[i] % 2 == 0 && i % 2 == 1) {
                tmp = A[i];
                A[i] = A[index];
                A[index] = tmp;
            }

            if (A[index] % 2 == 0)
                index += 2;

            if (A[i] % 2 == 1 && i % 2 == 1)
                i++;
        }

        return A;
    }
};
