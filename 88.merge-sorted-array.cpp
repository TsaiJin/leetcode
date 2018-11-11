/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (33.21%)
 * Total Accepted:    286.9K
 * Total Submissions: 853.6K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 * Note:
 *
 *
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 *
 *
 * Example:
 *
 *
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 *
 * Output: [1,2,2,3,5,6]
 *
 *
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = m + n - 1;
        int nums1_end = m -1;
        int nums2_end = n - 1;
        while (nums1_end >= 0 && nums2_end >= 0) {
            if (nums1[nums1_end] >= nums2[nums2_end]) {
                nums1[end--] = nums1[nums1_end--];
            } else {
                nums1[end--] = nums2[nums2_end--];
            }
        }
        while(nums2_end >= 0) {
            nums1[end--] = nums2[nums2_end--];
        }
    }
};
