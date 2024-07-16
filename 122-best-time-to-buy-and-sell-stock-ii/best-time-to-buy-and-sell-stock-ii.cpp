class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        for(int j=0;j<2;j++){
            dp[n][j]= 0;
        }
        for(int i=n-1;i>=0;i--){
         
           
           dp[i][1]=      max((-prices[i]+dp[i+1][0]),(0+dp[i+1][1]));
            
           
    dp[i][0]=   max((prices[i]+dp[i+1][1]),(0+dp[i+1][0]));
            
            
           }
           
           return dp[0][1];
        

    }
};