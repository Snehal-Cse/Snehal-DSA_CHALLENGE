class Solution {
public:
   
    int maxProfit(int k, vector<int>& prices) {
     int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
       int profit= INT_MIN;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int cap = 1;cap<=k;cap++){
                    if(j){
            profit = max((-prices[i]+dp[i+1][0][cap]),(0+dp[i+1][1][cap]));
        }
        else{
            profit = max((prices[i]+dp[i+1][1][cap-1]),(0+dp[i+1][0][cap]));
        } 
                    dp[i][j][cap] = profit;
                }
            }
        }
        
        
        return dp[0][1][k];
        
        
        
        
        
        
        
    }
};


