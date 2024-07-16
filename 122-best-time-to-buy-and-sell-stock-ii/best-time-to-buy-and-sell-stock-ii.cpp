class Solution {
public:
    int f(vector<int>&prices, int i, vector<vector<int>>&dp, int buy){
        int n = prices.size();
        if(i==n){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit = 0;
        if(buy){
            profit = max((-prices[i]+f(prices, i+1, dp, 0)), (0+f(prices, i+1, dp, 1)));
        }
        else{
            profit = max((prices[i]+f(prices, i+1, dp, 1)),(0+f(prices, i+1, dp, 0)));
        }
        return dp[i][buy]= profit;
     
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return f(prices, 0, dp, 1);
    }
};