class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return nums;
        int read=0;
        int write=0;
        while(read<n){
            if(nums[read]%2==0){
                swap(nums[read],nums[write]);
                write++; //swap and increment 
            }
        read++; //always move read till n
        }
    return nums;
    }
};