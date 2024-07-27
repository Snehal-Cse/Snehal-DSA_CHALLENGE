class Solution {
public:
    int f(vector<vector<int>>&dp, vector<int>&prices, int i, int buy){
    if(i==prices.size()){
        return 0;
    }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit = INT_MIN;
        if(buy){
            profit = max((-prices[i] + f(dp, prices, i+1, 0)),(0+f(dp, prices, i+1,                 1)));
        }
        else{
            profit = max((prices[i]+ f(dp, prices, i+1, 1)),(0+f(dp, prices, i+1, 0)));
        }
       
       return dp[i][buy]= profit;
    
    }
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<vector<int>>dp(n, vector<int>(2, -1));
      return f(dp, prices, 0, 1);
    }
};