class Solution {
public:
    int f(vector<int>&nums, vector<int>&dp, int n){
     if(n==0){
         return nums[0];
     }   
   if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
     int left = nums[n]+ f(nums, dp, n-2);
      int right = 0 + f(nums, dp, n-1);
        return dp[n]= max(left, right); 
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
      vector<int>dp(n, -1);
       return f(nums, dp, n-1);
    }
};