class Solution {
public:
    int cnt =0;
    void merge(vector<int>&nums, int s, int e, int m){
         int i = s;
         int j = m+1;
         vector<int>temp;
         while(i<=m && j<=e){
             if(nums[i]<=nums[j]){
                 temp.push_back(nums[i]);
                 i++;
             }
             else{
                 temp.push_back(nums[j]);
                 j++;
             }
         }
        while(i<=m){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=e){
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=0;i<temp.size();i++){
            nums[s+i]= temp[i];
        }
        
    }
    void countPairs(vector<int>&nums, int s, int e, int m){
         int right = m+1;
         for(int i=s;i<=m;i++){
             while(right<=e && nums[i]> 2LL*nums[right]){
                 right++;
             }
           cnt += (right - (m+1));
         }
    }
    void mergeSort(vector<int>&nums, int s, int e){
        if(s<e){
            int m = s+(e-s)/2;
            mergeSort(nums, s, m);
            mergeSort(nums, m+1, e);
            countPairs(nums,s,e,m);
            merge(nums, s, e, m);
        }
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);   
        return cnt;    
    }
};