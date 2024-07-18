class Solution {
public:
    
  int firstPos(vector<int>&nums, int target){
        int s = 0;
      int ans =-1;
        int e = nums.size()-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]== target){
                ans = m;
                e = m-1;
            }
            else if(nums[m] < target){
                s=m+1;
            }
            else {
                e = m-1;
            }
        }
      return ans;
    }
     int lastPos(vector<int>&nums, int target){
        int s = 0;
        int ans =-1;
        int e = nums.size()-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m] == target){
                ans = m;
                s=m+1;
            }
            else if(nums[m] < target){
                s=m+1;
            }
            else {
                e = m-1;
            }
        }
      return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int>ans;
        int n = nums.size();
        int first = firstPos(nums, target);
        int last =  lastPos(nums, target);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
        
    }
};