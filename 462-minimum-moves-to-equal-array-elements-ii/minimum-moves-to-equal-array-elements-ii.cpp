class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum =0;
        int n = nums.size();
       for(int i=0;i<n/2;i++){
           int a =  nums[n-i-1] - nums[i];
           sum = sum+a;
       } 
        return sum;
    }
};