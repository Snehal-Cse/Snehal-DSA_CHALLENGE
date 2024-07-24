class Solution {
public:
    void f(vector<int>&nums, set<vector<int>>&st, vector<int>&output, int i, int n){
        if(i>n-1){
            sort(output.begin(), output.end());
            st.insert(output);
            return;
        }
        
        f(nums, st, output, i+1, n);
        output.push_back(nums[i]);
        f(nums, st, output, i+1,n);
        output.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<int>output;
        set<vector<int>>st;
        int i =0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        f(nums, st, output, i, n);
         vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};