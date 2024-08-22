class Solution {
public:
    int f(vector<vector<int>>&dp, int i, int j, string &word1, string &word2){
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini = 0;
    if(word1[i]==word2[j]){
        mini = f(dp, i-1, j-1, word1, word2);
    }
    else{
        mini = min({(1+f(dp, i-1, j, word1, word2)),(1+f(dp, i, j-1, word1, word2)),(1+f(dp, i-1, j-1, word1, word2))});
    }
    
   return dp[i][j]= mini;
    
}
    int minDistance(string word1, string word2) {
       int n = word1.length();
       int m = word2.length();
       vector<vector<int>>dp(n, vector<int>(m, -1));
       return f(dp, n-1, m-1, word1, word2); 
        
    }
};