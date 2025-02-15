class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        if( k==0 || n==1 ) return;
            //temp
            // for(int i=n-k; i<n; i++){
            //     temp.push_back(nums[i]);
            // }
            vector<int> temp(nums.end() - k, nums.end());

            //shifting
            for(int i=n-1;i>=k;i--){
                nums[i]=nums[i-k];
            }
            //put back temp
            for(int i=0;i<k;i++){
                nums[i]=temp[i];
            }
        }
    
};