class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp; //stores number and its index
        for( int i=0;i<nums.size();i++){
            int n2 = target-nums[i];
                if(mpp.count(n2)){   //check if map has an element
                    return {mpp[n2],i};
                }
                mpp[nums[i]] = i;  
                //key          value
        }
    return {};
    }
};