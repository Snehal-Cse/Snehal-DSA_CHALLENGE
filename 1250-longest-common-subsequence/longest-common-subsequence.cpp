class Solution {
public:
    int f(vector<vector<int>>&dp, string &text1, string &text2, int i, int j){
        if(i<0 || j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int cnt = 0;
        if(text1[i]==text2[j]){
            cnt = 1 + f(dp, text1, text2, i-1, j-1);
        }
        else{
            cnt = max(0+f(dp, text1, text2, i-1, j), 0+f(dp, text1, text2, i, j-1));
        }
        return dp[i][j]= cnt;
    }
    int longestCommonSubsequence(string text1, string text2) {
      int n1 = text1.size();
      int n2 = text2.size();
        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        return f(dp, text1, text2, n1-1, n2-1);
    }
};