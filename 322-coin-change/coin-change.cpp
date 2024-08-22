class Solution {
public:
    int f(vector<vector<int>>&dp, vector<int>&coins, int amount, int i){
       if(amount==0){
           return 0;
       }
        if(i==0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            return 1e7;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int take = 1e7;
        if(coins[i]<=amount){
            take = 1 + f(dp, coins, amount-coins[i], i);
        }
        int notTake = f(dp, coins, amount, i-1);
        return dp[i][amount]= min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int a =  f(dp, coins, amount, n-1);
        if(a>=1e7){
            return -1;
        }
        return a;
    }
};