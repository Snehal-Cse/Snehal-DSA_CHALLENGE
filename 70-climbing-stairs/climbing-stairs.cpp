#include<vector>
class Solution {
public:
 int f(vector<int>&dp, int i){
     if(i<=1){
         return 1;
     }
    if(dp[i]!=-1){
        return dp[i];
    } 
     return dp[i] = f(dp, i-1) + f(dp, i-2);
 }   
 int climbStairs(int n) {
   vector<int>dp(n+1, -1);
     return f(dp, n);
    }
};