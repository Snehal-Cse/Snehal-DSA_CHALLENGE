class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
      int n = prices.size();
        vector<vector<int>>dp(n+2, vector<int>(2, 0));
        int profit =INT_MIN;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                 profit = max((-prices[i]+dp[i+1][0]),(0+dp[i+1][1]));   
                }
                else{
                    profit = max((prices[i]-fee+dp[i+1][1]),(0+dp[i+1][0])); 
                }
                dp[i][j]=profit;
            }
        }
     return dp[0][1];
    }
};