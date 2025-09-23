class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,t=0;
        int n=nums.size();
        for(int i:nums){
            if(i==0) z++;
            else if (i==1) o++;
            else t++;
        }
        for(int i=0;i<n;i++){
            if(z){
                nums[i]=0;
                z--;
            }
            else if(o){
                nums[i]=1;
                o--;
            }
            else {
                nums[i]=2;
            }
        }
    }
};