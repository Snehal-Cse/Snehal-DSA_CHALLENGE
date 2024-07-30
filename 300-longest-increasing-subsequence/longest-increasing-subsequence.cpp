class Solution {
public:
    int f(vector<int>&nums, vector<vector<int>>&dp, int i, int prev){
        int n = nums.size();
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int notTake = f(nums, dp, i+1, prev);
        int take =0;
        if(prev==-1 || nums[i]>nums[prev]){
            take = 1+f(nums, dp, i+1, i);
        }
        return dp[i][prev+1]= max(take, notTake);
     
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return f(nums, dp, 0, -1);
    }
};