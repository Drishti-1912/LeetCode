class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int right=0;
        if(right==-1) return; //no non zeroes
        for(int right=0;right<nums.size();right++){
            if(nums[right]!=0){
                swap(nums[left],nums[right]);
                left++;
            }
        }
    }
};