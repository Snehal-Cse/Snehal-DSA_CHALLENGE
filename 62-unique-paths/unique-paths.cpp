class Solution {
public:
    int f(vector<vector<int>>&dp, int i, int j){
        if(i==0 && j==0){
            return 1;
        }
      
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up =0;
        if(i>=1){
             up = f(dp, i-1, j);
        }
         int left=0;
        if(j>=1){
            left = f(dp, i, j-1);
        }
      
        return dp[i][j] = up+left;
    }
    
    int uniquePaths(int m, int n) {
      vector<vector<int>>dp(m, vector<int>(n, -1));
        return f(dp, m-1, n-1);
//        dp[0][0]=1;
//        for(int i=0;i<m;i++){
//            for(int j=0;j<n;j++){
//                if(i==0 && j==0){
//                    continue;
//                }
//                int up =0;
//                if(i-1>=0){
//                   up = dp[i-1][j]; 
//                }
//                int down =0;
//                if(j-1>=0){
//                  down = dp[i][j-1];   
//                }
              
//                dp[i][j]= up+down;
//            }
//        }
//         return dp[m-1][n-1];
    }
};