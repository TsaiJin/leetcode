class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int current_cmp_val;
        int to_be_replaced_index;
        int to_be_checked_index;

        current_cmp_val = nums[0];
        to_be_replaced_index = 1;
        to_be_checked_index = 1;

        int tmp_index;
        int swap_val;

        while (to_be_checked_index < nums.size()) {
            tmp_index = to_be_checked_index;
            while (nums[tmp_index] == current_cmp_val)
                tmp_index++;
            if (tmp_index >= nums.size())
                return to_be_replaced_index;
            swap_val = nums[to_be_replaced_index];
            nums[to_be_replaced_index] = nums[tmp_index];
            current_cmp_val = nums[to_be_replaced_index];
            nums[tmp_index] = swap_val;
            to_be_replaced_index++;
            to_be_checked_index = tmp_index + 1;
        }
        return to_be_replaced_index;
    }
};
