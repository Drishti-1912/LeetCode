class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0; // Count of jumps
        int l = 0, r = 0; 
        int farthest = 0; // Farthest point reachable

        while (r < nums.size() - 1) {
            for (int i = l; i <= r; ++i) {
                farthest = max(farthest, i + nums[i]); // Update farthest reach
            }
            l = r + 1; // Move to the next range
            r = farthest; // Update range to farthest reachable
            ++res; // Increment jump count
        }
        return res;
    }
};


