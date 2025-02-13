class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     set<int> uniqueNums(nums.begin(),nums.end());
     //using hash set for unique elements
     int index=0;
      for (int num : uniqueNums) {
            nums[index++] = num;
        }
     return index;
    }

};