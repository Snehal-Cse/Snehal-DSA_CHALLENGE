class Solution {
public:
   static bool cmp(vector<int>&a, vector<int>&b){
     return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end(), cmp);
       vector<vector<int>>merged;
       for(int i=0; i<intervals.size(); i++){
           if(merged.empty() || merged.back()[1] < intervals[i][0]){
               merged.push_back(intervals[i]);
           }
           else{
               vector<int>v = merged.back();
               merged.pop_back();
               merged.push_back({min(v[0], intervals[i][0]), max(v[1], intervals[i][1])});
           }
       }
        return merged;
        
        
    }
};