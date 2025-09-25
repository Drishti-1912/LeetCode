class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0], maxpro=0;
        for(int i=0;i<prices.size();i++){
            int cost=prices[i]-mini;
            maxpro=max(maxpro,cost);
            mini=min(mini,prices[i]);
        }
        return maxpro;
    }
};