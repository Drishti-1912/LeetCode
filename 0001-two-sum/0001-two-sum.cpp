class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numWithIndex;

        for (int i = 0; i < nums.size(); ++i) {
            numWithIndex.push_back({nums[i], i});
        }

        sort(numWithIndex.begin(), numWithIndex.end());

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - numWithIndex[i].first;

            int low = i + 1, high = nums.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (numWithIndex[mid].first == complement) {
                    return {numWithIndex[i].second, numWithIndex[mid].second};
                }
                else if (numWithIndex[mid].first < complement) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return {-1, -1};
    }
};
