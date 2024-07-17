#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
      int  j =0;
      int  k=0;
        int n = nums.size();
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
               continue;
            }
            int fix = nums[i];
            j= i+1;
            k = n-1;
            while(j<k){
              int  sum = fix+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({fix, nums[j], nums[k]});
                    while(j<k && nums[j]==nums[j+1]){
                        j++;
                    }
                     while(k>j && nums[k]==nums[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    k--;
                }
            }
            
        }
        return ans;
    }
};
