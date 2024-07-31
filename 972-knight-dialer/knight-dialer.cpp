class Solution {
public:
    int MOD = 1000000007;
    vector<vector<int>>moves = {
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {3,9,0},
        {},
        {1,7,0},
        {2,6},
        {1,3},
        {4,2},   
    };
    long f(vector<vector<int>>&dp, int remain, int dig){
        if(remain ==0){
            return 1;
        }
        if(dp[remain][dig]!=-1){
            return dp[remain][dig];
        }
        long ways = 0;
        for(auto d : moves[dig]){
            ways += f(dp, remain-1, d);
            ways = ways%MOD;
        }
        
        return dp[remain][dig]= ways;
        
    }
    int knightDialer(int n) {
     vector<vector<int>>dp(n, vector<int>(10, -1));
        int ans=0;
        for(int i=0;i<10;i++){
           ans += f(dp, n-1, i);
            ans = ans%MOD;
        }
        return ans;
    }
};