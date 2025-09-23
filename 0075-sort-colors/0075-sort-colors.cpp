class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> sorted;
        for(int x:nums){
            sorted[x]++;
        }
        int idx=0;
        for(auto &p:sorted){
            for(int i=0;i<p.second;i++){
                nums[idx++] = p.first;
            }
        }
    }
};