#include<climits>
#include<algorithm>
#include<vector>
class Solution {
public:
   void f(vector<vector<int>>&ans, vector<int>&output, int n, int target, int i, vector<int>&candidates, int sum){
           if(sum == target){
               ans.push_back(output);
               return;
           }
       if(i>=n || sum>target){
           return;
       }
       for(int j=i;j<candidates.size();j++){
           if(j>i && candidates[j] == candidates[j-1]){
               continue;
           }
           output.push_back(candidates[j]);
           f(ans, output, n, target,j+1, candidates, sum+candidates[j]);
           output.pop_back();
       }
      
 
       
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     vector<vector<int>>ans;
     vector<int>output;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        f(ans, output, n, target,0, candidates, sum);
        return ans;
       
    }
};