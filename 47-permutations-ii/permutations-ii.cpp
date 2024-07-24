class Solution {
public:
    void f(vector<int>&nums, int i, int n, set<vector<int>>&st){
        if(i>=n){
          
            st.insert(nums);
            return;
        }
        for(int j=i; j<n; j++){
          if(i<j && nums[j]== nums[j-1]){
              continue;
          }     
            swap(nums[i], nums[j]);
            f(nums,i+1,n, st);
             swap(nums[i], nums[j]);
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        f(nums, 0, n, st);
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};