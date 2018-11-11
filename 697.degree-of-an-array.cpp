/*
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (47.60%)
 * Total Accepted:    33.2K
 * Total Submissions: 69.7K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 *
 * Example 1:
 *
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation:
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 *
 *
 *
 *
 * Example 2:
 *
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 *
 *
 *
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 *
 */

struct Position {
    int first_position;
    int last_position;
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        int array[50000];
        memset(array, 0, 50000);
        struct Position position_array[50000];
        memset(position_array, 0, 50000);

        int largest_degree = 0;
        int min_array_len = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            array[i]++;
            if (position_array[i].first_position == 0)
                position_array[i].first_position = i;
            else
                position_array[i].last_position = i;

            if (array[i] > largest_degree) {
                largest_degree = array[i];
                if (min_array_len >
                        position_array[i].last_position - position_array[i].first_position)
                    min_array_len =
                        position_array[i].last_position - position_array[i].first_position;
            }
        }
        return min_array_len + 1;
    }
};
