class Solution {
public:
    int f(vector<int>&dp, string s, int i){
        int n = s.length();
        if(i>=n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans =0;
        if(i<n && s[i]!='0'){
          ans += f(dp, s, i+1);  
        }
        if(i+1<n && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))){
            ans += f(dp, s, i+2);
        }
        return dp[i]= ans;
        
    }
    int numDecodings(string s){
     int n = s.length();
     vector<int>dp(n, -1);
     return f(dp, s, 0);   
    }
};