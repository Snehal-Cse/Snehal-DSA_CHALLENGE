#include <map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l =0;
        int r = 0;
        map<char, int>mp;
       int  maxF = 0;
       int maxL=0;
        while(r<s.size()){
         mp[s[r]]++;
         maxF= max(maxF, mp[s[r]]);
          int change = (r-l+1)-maxF;
            if(change<=k){
                maxL = max(r-l+1, maxL);
            }
            if(change>k){
          mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
               
                  l++;
            }
            r++;
        }
        return maxL;
    }
}; // Corrected the logic issue
