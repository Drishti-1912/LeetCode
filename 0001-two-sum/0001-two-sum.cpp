class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    // Create a map to store numbers and their indices
    unordered_map<int, int> map;
    vector<int> result(2); // To store the resulting indices

    for(int i=0;i<nums.size();i++){
        int rem=target-nums[i];                 //calculate complement

    // Check if the complement exists in the map
    if (map.find(rem) != map.end()) {
        result[0] = map[rem]; // Index of the complement
        result[1] = i;       // Current index
        return result;       // Return the result
        }

    // Add the current number and its index to the map
         map[nums[i]] = i;
        }

    return result;
    }
};