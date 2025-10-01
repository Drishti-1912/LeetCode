class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int ind = -1; // Find the first decreasing element from the right

        // Step 1: Find the largest index 'ind' such that nums[ind] < nums[ind + 1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // If no such index exists, the array is in descending order (largest permutation)
        // In this case, reverse the entire array to get the smallest permutation.
        if (ind == -1) {
            std::reverse(nums.begin(), nums.end());
            return; // Return after reversing for the edge case
        }

        // Step 2: Find the largest index 'j' greater than 'ind' such that nums[j] > nums[ind]
        for (int i = n - 1; i > ind; i--) { // Corrected loop condition: i > ind
            if (nums[i] > nums[ind]) {
                std::swap(nums[i], nums[ind]); // Swap nums[ind] with nums[j]
                break;
            }
        }

        // Step 3: Reverse the subarray from ind + 1 to the end
        std::reverse(nums.begin() + ind + 1, nums.end());
    }
};