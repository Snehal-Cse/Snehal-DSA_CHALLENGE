#include<vector>
class Solution {
public:
    void f(vector<int>nums, vector<vector<int>>&ans, int n, int i, vector<int>number ){
     if(i>n-1){
        ans.push_back(number);
         return;
     }
       f(nums, ans, n, i+1,number);
      number.push_back(nums[i]);
       f(nums, ans, n, i+1, number);
        number.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
        vector<int>number;
        int n = nums.size();
        f(nums, ans, n, 0, number);
        return ans;
    }
};
