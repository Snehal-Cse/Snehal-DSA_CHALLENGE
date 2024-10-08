class Solution {
public:
   
    bool canPartition(vector<int>& nums) {
     int sum =0;
     int n = nums.size();
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
     if(sum%2!=0){
       return false;  
     }   
    vector<vector<bool>>dp(n, vector<bool>((sum/2)+1 , false));
        int total = sum/2;
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
     if(nums[0]<=total){
         dp[0][nums[0]]=true;
     }
     for(int i=1;i<n;i++){
         for(int j=1;j<=total; j++){
             bool take = false;
             if(nums[i]<=j){
                 take = dp[i-1][j-nums[i]];
             }
             bool notTake = dp[i-1][j];
             dp[i][j]= take||notTake;
         }
     }
      return dp[n-1][total];  
    }
};