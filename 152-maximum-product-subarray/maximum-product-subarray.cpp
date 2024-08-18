class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
      long long maxi = INT_MIN;
      long long prefix = 1;
        long long n = nums.size();
      long long suffix = 1;
        for(int i=0;i<n;i++){
            if(prefix == 0 || prefix<INT_MIN){
             prefix=1; 
          }
           if(suffix == 0 || suffix<INT_MIN){
             suffix=1; 
          }  
        
          prefix = prefix*nums[i];
          suffix = suffix*nums[n-i-1];
          
            maxi= max(maxi, max(prefix, suffix));
        }
        return maxi;
        }
};