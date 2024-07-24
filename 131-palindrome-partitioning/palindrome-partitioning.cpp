class Solution {
public:
    bool isPalindrone(string st, int s, int e){
      
        while(s<e){
            if(st[s]!=st[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
  void f(vector<vector<string>>&ans, vector<string>&output, string s, int n, int i){
     if(i==n){
         ans.push_back(output);
         return;
     }
      for(int j = i; j<n;j++){
          if(isPalindrone(s, i, j)){
              output.push_back(s.substr(i, j-i+1));
              f(ans, output, s, n, j+1);
              output.pop_back();
          }
      }
      
      
      
      
  }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>output;
        int n = s.length();
        f(ans, output, s, n, 0);
        return ans;
    }
};