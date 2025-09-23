class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        int idx=0;
        for(auto &it:freq){
            for(int i=0;i<it.second;i++){
                nums[idx++] = it.first;
            }
        }
    }
};