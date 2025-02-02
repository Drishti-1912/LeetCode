class Solution {
public:
    bool check(vector<int>& nums) {
        int pivot;
        int n = nums.size();
        for (pivot = 0; nums[(pivot + 1) % n] >= nums[pivot % n] && pivot < n ; pivot++) {
            
        }
        pivot++;
        pivot %= n;
        for (int k = 0; k < n - 1; k++) {
            if (nums[(pivot + k + 1) % n] < nums[(pivot + k) % n]) {
                return false;
            }
        }
        return true;
    }
}; 