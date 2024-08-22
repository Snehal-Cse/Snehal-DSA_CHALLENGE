class Solution {
public:
    long long f(vector<vector<long long>>&dp, vector<vector<int>>&grid, int i, int j, int n, int m){
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i<0 || j<0){
            return LLONG_MAX;
        }
        long long up =  (i>0) ? grid[i][j] + f(dp, grid, i-1, j, n, m) : LLONG_MAX;
        long long left = (j>0) ?  grid[i][j] + f(dp, grid, i, j-1, n, m): LLONG_MAX ;
        return dp[i][j]= min(up, left);
        
    }
  
    int minPathSum(vector<vector<int>>& grid) {
     int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>>dp(n, vector<long long>(m, -1));
        return f(dp, grid, n-1, m-1, n, m); 
    }
};