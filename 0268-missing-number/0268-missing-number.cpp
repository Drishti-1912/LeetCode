class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // check numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }
            if (!found) return i;
        }
        return -1; // should never reach here
    }
};
