class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int resultSum=nums[0]+nums[1]+nums[2];
        int minDiff=INT_MAX;
        //fix first element and fin other 2 using 2sum approach
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1;
            int right=nums.size()-1;

            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==target) return target;
                if(sum<target) left++;
                else right--;
            
            int diffToTarget=abs(sum-target);
            if(diffToTarget<minDiff){
                resultSum=sum;
                minDiff=diffToTarget;
            }

        }

    }
    return resultSum;

    }
};