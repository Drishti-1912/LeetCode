class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); ) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);  // don't increment i
            } else {
                i++;  // only increment if not erased
            }
        }
        return nums.size();
    }
};
