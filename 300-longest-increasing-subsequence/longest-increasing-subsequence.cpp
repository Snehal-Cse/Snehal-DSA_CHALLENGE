class Solution {
public:
    int f(vector<vector<int>>&dp, int n, vector<int>&nums, int i, int prev){ 
        if(i==n){
            return 0;
        }
        
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int take =0;
        if(prev==-1 || nums[prev]<nums[i]){
            take = 1+f(dp, n, nums, i+1, i);
        }
      
          int   nottake = f(dp, n, nums, i+1, prev);
        
        return dp[i][prev+1]= max(take, nottake); 
        
    }  
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
      vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return f(dp, n, nums, 0, -1);
    }
};