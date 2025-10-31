class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<vector<int>> moves = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    long long count_ways_solveME(int digit, int len, vector<vector<long long>>& dp) {
        if (len == 1) return 1;
        if (dp[digit][len] != -1) return dp[digit][len];
        
        long long total = 0;
        for (int next : moves[digit]) {
            total = (total + count_ways_solveME(next, len - 1, dp)) % MOD;
        }
        return dp[digit][len] = total;
    }

    int knightDialer(int n) {
        long long ans = 0;
        vector<vector<long long>> dp(10, vector<long long>(n + 1, -1));
        for (int digit = 0; digit <= 9; digit++) {
            ans = (ans + count_ways_solveME(digit, n, dp)) % MOD;
        }
        return ans;
    }
};
