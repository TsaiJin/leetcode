class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int tmp;
        int found = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.size() - found <= i) {
                break;
            }
            if (nums[i] == val) {
                for (int j = nums.size() - found - 1; j > i; j--) {
                    if (nums[j] != val) {
                        tmp = nums[j];
                        nums[j] = val;
                        nums[i] = tmp;
                        break;
                    } else {
                        found++;
                    }
                }
                found++;
            }
        }
        return nums.size() - found;
    }
};
