class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int,int> map; //freq of nums2 elements

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int num: nums2){
            map[num]++;
        }
    }
    
    void add(int index, int val) {
        // Update frequency map for nums2[index]
        map[nums2[index]]--;           // Remove old value
        nums2[index] += val;            // Update value
        map[nums2[index]]++;           // Add new value
    }
    
    int count(int tot) {
        int result = 0;
        for (int num : nums1) {
            int complement = tot - num;
            if (map.find(complement) != map.end()) {
                result += map[complement];
            }
        }
        return result;
    }
};


/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */