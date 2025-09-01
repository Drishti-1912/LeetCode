class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int left=1,right=nums.size()-1;
       int dup=-1;

       while(left<=right){
        int mid=left+(right-left)/2;

        // Count how many numbers are <= mid
        int cnt=0;
        for(int num:nums){
            if(num<=mid) cnt++;
        }
        if(cnt>mid){
            dup=mid; //possible dup
            right=mid-1;
        }else{
            left=mid+1;
        }
       }
    return dup;
    }
};