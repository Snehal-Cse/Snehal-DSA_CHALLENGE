class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;
        for(auto s : strs){
            string org = s;
            sort(s.begin(), s.end());
            mp[s].push_back(org);
        }
        for(auto [key, vecOfStr] : mp){
            ans.push_back(vecOfStr);
        }
        return ans;
        }
};