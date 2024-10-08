#include<map>
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum =0;
        int rem =0;
        int cnt =0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem = sum%k;
            if(rem<0){
                rem = rem+k;
            }
            if(mp.find(rem)!=mp.end()){
                cnt += mp[rem];
            }
            mp[rem]++;
        }
        return cnt;

    }
};