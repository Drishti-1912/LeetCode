class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sort the array to easily avoid duplicates

        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            unordered_set<int> seen; // Hash map to store the complements
            int target = -nums[i];  // We want nums[i] + nums[j] + nums[k] = 0, so target is -nums[i]
            
            // Start with the next element after nums[i] for the second element
            for (int j = i + 1; j < nums.size(); j++) {
                int complement = target - nums[j]; // Find complement for nums[j]
                
                if (seen.count(complement)) { // If the complement exists, we have found a valid triplet
                    result.push_back({nums[i], nums[j], complement});
                    
                    // Skip duplicates for the second element
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                        j++;
                    }
                }
                seen.insert(nums[j]); // Add the current element to the hash map for future reference
            }
        }

        return result;
    }
}; 
