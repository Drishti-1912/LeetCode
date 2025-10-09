class Solution {
public:
    long long minTime(vector<int>& arr, vector<int>& kd) {
        int n = arr.size(), m = kd.size();

        vector<long long> dp(n + 1, 0);
        
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                dp[i + 1] = max(dp[i + 1], dp[i]) + 1LL * kd[j] * arr[i];
            }
            for (int i = n - 1; i > 0; --i) {
                dp[i] = dp[i + 1] - 1LL * kd[j] * arr[i];
            }
        }
        
        return dp[n];
    }

};