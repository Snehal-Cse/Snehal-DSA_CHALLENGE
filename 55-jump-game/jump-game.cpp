class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        int in =0;
       
        int n = nums.size();
       for(int i=0;i<nums.size()-1;i++){
           if(i>maxi){
               return false;
           }
         in = i+nums[i];
           maxi = max(maxi, in);
       }
        return (maxi>=n-1);
    }
};