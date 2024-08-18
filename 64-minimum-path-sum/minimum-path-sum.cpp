class Solution {
public:
    int f(vector<vector<int>>&dp, int i, int j, vector<vector<int>>&grid){
        if(i==0 && j==0){
            return grid[0][0]; 
        }
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }    
        int up = (i>0) ? grid[i][j] + f(dp, i-1, j, grid) : INT_MAX;
        int left = (j>0) ? grid[i][j] + f(dp, i, j-1, grid) : INT_MAX;
        return dp[i][j] = min(up, left);  
            
    }
  
    int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int  n =  grid[0].size();
      vector<vector<int>>dp(m, vector<int>(n, -1));
       return f(dp, m-1, n-1, grid); 
    }
};