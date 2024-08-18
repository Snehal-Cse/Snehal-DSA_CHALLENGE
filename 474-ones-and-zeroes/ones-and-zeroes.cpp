class Solution {
public:
    
 pair<int, int>count(string &str){
     int zero = 0;
     int one = 0;
     for(char c: str){
         if(c=='0'){
             zero++;
         }
         else if(c=='1'){
             one++;
         }   
     }  
     return {zero, one};
 }
   
    int f(vector<vector<vector<int>>>&dp, vector<string>&strs,int len, int i, int j){  
        
        int p = strs.size();
        if(len >=p || (i==0 && j==0)){
            return 0;
        }
        
        
    if(dp[len][i][j]!=-1){
        return dp[len][i][j];
    } 
    auto [cntZero, cntOne] =  count(strs[len]);
        int take =0;
        if(cntZero<=i && cntOne<=j){
             take = 1 + f(dp, strs, len+1, i-cntZero, j-cntOne);
        }
    int notTake = f(dp, strs, len+1, i, j);
    return dp[len][i][j] = max(take, notTake);  
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
    int a  = strs.size();
    vector<vector<vector<int>>>dp(a+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
    return f(dp, strs, 0, m, n);
    }
};