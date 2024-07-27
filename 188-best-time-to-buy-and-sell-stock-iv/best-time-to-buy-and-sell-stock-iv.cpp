class Solution {
public:
    int f(vector<int>&prices, vector<vector<vector<int>>>&dp, int i, int buy, int cap){
        if(cap==0 || i==prices.size()){
            return 0;
        }
        if(dp[i][buy][cap]!=-1){
            return dp[i][buy][cap];
        }
        int profit = INT_MIN;
        if(buy){
            profit = max((-prices[i]+f(prices, dp, i+1, 0, cap)),(0+f(prices, dp, i+1, 1, cap)));
        }
        else{
            profit = max((prices[i]+f(prices, dp, i+1, 1, cap-1)),(0+f(prices, dp, i+1, 0, cap)));
        }
       return dp[i][buy][cap]= profit;
        
    }
    int maxProfit(int k, vector<int>& prices) {
     int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(prices, dp, 0, 1, k);
    }
};


