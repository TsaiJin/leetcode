class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int max_sum = nums[0];
        int max_before = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (max_before < 0)
                max_before = nums[i];
            else
                max_before += nums[i];
            if (max_before > max_sum)
                max_sum = max_before;
        }
        return max_sum;
    }
};
