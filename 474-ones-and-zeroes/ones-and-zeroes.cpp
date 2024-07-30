class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
    vector<vector<vector<int>>>dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
    for(int i=1;i<=strs.size();i++){
        for(int j=0;j<=m;j++){
            for(int k =0;k<=n;k++){
               int cntZero = count(strs[i-1].begin(), strs[i-1].end(), '0');
                int cntOne = strs[i-1].size()-cntZero; 
                int take =0;
                if(j-cntZero>=0 && k-cntOne>=0){
               take =1+dp[i-1][ j-cntZero][k-cntOne] ;
        }
              int notTake = dp[i-1][j][k];
              dp[i][j][k]= max(take, notTake);
            }
        }
    }
       return dp[strs.size()][m][n]; 
    }
};