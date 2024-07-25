class Solution {
public:
    
    
    int rob(vector<int>& nums) {
          int n = nums.size();
         if (n == 0) return 0; // Edge case: empty array
        if (n == 1) return nums[0]; // Edge case: only one house
      
       vector<int>dp(n, 0);
       dp[0]=nums[0];
        dp[1]= max(nums[0], nums[1]);
      for(int i=2;i<n;i++){
     
        
            int  left = nums[i]+ dp[i-2] ;
          
        
         int right = 0 + dp[i-1];
         dp[i]= max(left, right); 
      }
        
        
        return dp[n-1];
        
        
        
        
        
        
        
        
    }
};