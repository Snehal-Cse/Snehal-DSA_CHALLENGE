class Solution {
public:
    int f(vector<vector<int>>&dp, vector<int>&nums, int i, int prev){
        int n = nums.size();
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
       int take = 0;
        if(prev == -1 || nums[prev]<nums[i]){
           take  = 1 + f(dp, nums, i+1, i);
        }
    
          int notTake   = f(dp, nums, i+1, prev);
        
       
        return dp[i][prev+1] = max(take,notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return f(dp, nums, 0, -1);
    }
};