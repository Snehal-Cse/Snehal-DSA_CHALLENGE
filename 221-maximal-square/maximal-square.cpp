class Solution {
public:
      int maxi =  INT_MIN;
    int f(vector<vector<char>>&matrix, vector<vector<int>>&dp, int i, int j, int &maxi){
       int n = matrix.size();
       int m = matrix[0].size();
        if(i>=n || j>=m ){
            return 0;
        }
       if(dp[i][j]!=-1){
           return dp[i][j];
       } 
      
       
        int a = f(matrix, dp, i+1, j, maxi);
        int b = f(matrix, dp, i, j+1, maxi);
        int c = f(matrix, dp, i+1, j+1, maxi);
        if(matrix[i][j]=='1'){
           int mini =  min({a,b,c});
            dp[i][j] = 1 + mini;
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
        
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();
      vector<vector<int>>dp(n, vector<int>(m, -1));
        int maxi =0;
      f( matrix,dp, 0, 0, maxi);
        return maxi*maxi;
    }
};