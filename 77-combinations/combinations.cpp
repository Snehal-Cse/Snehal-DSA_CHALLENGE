class Solution {
public:
    void f(vector<vector<int>>&ans, int n, int k, int i, vector<int>&output, vector<int>&nums){
         if(i>=n){
             if(output.size()==k){
                 ans.push_back(output);
             }
             return;
         }
        f(ans, n, k, i+1, output, nums);
        output.push_back(nums[i]);
        f(ans, n, k, i+1, output, nums);
        output.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>>ans;
        vector<int>output;
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
       f(ans, n, k,0, output, nums);  
       return ans;
    }
};