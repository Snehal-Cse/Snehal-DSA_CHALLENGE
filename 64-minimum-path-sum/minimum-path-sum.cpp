class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int up = 1e7;
                    int down = 1e7; 
                    if(i>0){
                        up = grid[i][j]+dp[i-1][j];
                    }
                    if(j>0){
                        down = grid[i][j] + dp[i][j-1];
                    }
                    dp[i][j] = min(up, down);
                }
               
                
            }
        }
        
        return dp[m-1][n-1];
        
    }
};
