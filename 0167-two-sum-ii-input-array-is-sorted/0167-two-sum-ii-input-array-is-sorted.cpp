class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int left=0;
        int right=num.size()-1;

        while(left<right){
            int sum=num[left]+num[right];
            if(sum==target) return {left+1,right+1};
            else if(sum<target) left++;
            else right--;
        }
        return {};
    }
};