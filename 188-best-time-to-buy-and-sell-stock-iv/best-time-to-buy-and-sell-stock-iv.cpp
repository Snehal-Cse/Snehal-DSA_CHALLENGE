class Solution {
public:
    int f(vector<vector<vector<int>>>&dp, int k, vector<int>&prices, int i, int buy){
       int n = prices.size(); 
       if(i==n || k==0){
           return 0;
       } 
        
        if(dp[i][k][buy]!=-1){
            return dp[i][k][buy];
        }
       int cnt =INT_MIN; 
        
       if(buy){
         cnt = max((-prices[i]+f(dp, k, prices, i+1, 0)), (f(dp, k, prices, i+1, 1)));
       }
       else{
          cnt =  max((prices[i]+f(dp, k-1, prices, i+1, 1)), (f(dp, k, prices, i+1, 0)));
       }
        return dp[i][k][buy]= cnt;
       
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return f(dp, k, prices, 0, 1);
    }
};


