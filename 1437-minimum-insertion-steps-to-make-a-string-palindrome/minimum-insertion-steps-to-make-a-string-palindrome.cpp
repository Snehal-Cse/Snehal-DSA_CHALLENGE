class Solution {
public:
    int f(vector<vector<int>>&dp, string &s, string &t, int i, int j){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int cnt =0;
        if(s[i]==t[j]){
            cnt = 1 + f(dp, s, t, i-1, j-1);
        }
        else{
            cnt = max((f(dp, s,t, i-1, j)),(f(dp, s, t, i, j-1)));
        }
        return dp[i][j]=cnt;
    
    
    }
    int minInsertions(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int a = f(dp, s,t, n-1, n-1);
        return n-a;
    }
};