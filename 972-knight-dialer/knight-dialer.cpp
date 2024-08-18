class Solution {
public:
  vector<vector<int>>arr = {
        {4,6},
        {6, 8},
        {7, 9},
        {8, 4},
        {0, 3, 9},
        {},
        {1, 7, 0},
        {2, 6},
        {1,3},
        {2,4}  
    };
    int f(vector<vector<int>>&dp, int remain, int dig){
        if(remain == 0){
            return 1;
        }
        if(dp[remain][dig]!=-1){
            return dp[remain][dig];
        }
        int ways =0;
        for(auto d : arr[dig]){
          ways += f(dp, remain-1, d);
          ways = ways%1000000007;
        }  
        return dp[remain][dig] = ways;
    }
    int knightDialer(int n) {
     vector<vector<int>>dp(n, vector<int>(10, -1));
     int ans =0;
     for(int i=0;i<10;i++){
         ans += f(dp, n-1, i);
         ans = ans%1000000007;
     }
     return ans;
    }
};