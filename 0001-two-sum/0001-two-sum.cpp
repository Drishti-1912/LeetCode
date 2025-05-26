class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
       for(int i=0;i<nums.size();i++){
        int curr=nums[i];
        int needed=target-curr;

        if (mpp.find(needed) != mpp.end()){ //“If the number we need to complete the target sum is already in the map, then return YES because a valid pair exists.”
        return {mpp[needed],i};
       }
       mpp[curr]=i; //store current number in the map
        }
    return {-1,-1};
    }
};