class Solution {
public:
    int f(vector<string>& strs, vector<vector<vector<int>>>&dp, int i, int m, int n){
        if(i<0){
            return 0;
        }
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int cntZero = count(strs[i].begin(), strs[i].end(), '0');
        int cntOne = strs[i].size()-cntZero;
        int take =0;
        if(m-cntZero>=0 && n-cntOne>=0){
       take =1+f(strs, dp, i-1, m-cntZero, n-cntOne);
        }
        int notTake = f(strs, dp, i-1, m, n);
        return dp[i][m][n]=max(take, notTake);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
    vector<vector<vector<int>>>dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
    return f(strs, dp, strs.size()-1, m, n);    
        
    }
};