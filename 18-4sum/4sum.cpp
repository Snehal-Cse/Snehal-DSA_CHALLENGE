class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        int n = nums.size();
      sort(nums.begin(), nums.end());
        for(int i=0;i<n-3;i++){
            for(int j =i+1;j<n-2;j++){
                int k = j+1;
                int p = n-1;
                while(k<p){
                    long long sum = nums[i]+nums[j];
                        sum+=nums[k];
                        sum+=nums[p];
                    if(sum==target){
                            vector<int>temp = {nums[i], nums[j], nums[k], nums[p]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        k++;
                        p--;
                        }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        p--;
                    }                   
                  }            
                    }
                }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};