class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
      long long int pref = 1;
      long long int suff =1;
      long long maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
           if(pref == 0 || pref<INT_MIN){
               pref = 1;
           } 
             if(suff == 0 || suff<INT_MIN){
               suff = 1;
           } 
          pref = pref * nums[i];
            suff = suff * nums[n-i-1];
            maxi = max(maxi, max(pref, suff));
        }
        return maxi;
     
        }
};