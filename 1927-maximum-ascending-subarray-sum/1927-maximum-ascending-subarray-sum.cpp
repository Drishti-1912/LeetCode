class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currsum=nums[0];
        int sum=0;
        int inc=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                currsum+=nums[i];
                // cout<<nums[i]<< " ";
            }
            else {
                sum=max(sum,currsum);
                // cout<<endl<<sum<<endl;
                currsum=nums[i];
            }
        }
        sum=max(sum,currsum);
        return sum; 
    }
};