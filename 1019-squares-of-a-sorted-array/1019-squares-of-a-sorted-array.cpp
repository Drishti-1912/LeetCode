class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());

        int left=0;
        int right=nums.size()-1;
        
        for(int pos=nums.size()-1 ; pos>=0 ; pos--){
            if(abs(nums[right])>abs(nums[left])){
                res[pos]=nums[right]*nums[right];
                right--;
            }
            else{
                res[pos]=nums[left]*nums[left];
                left++;
            }
        }

    return res;

    }
};