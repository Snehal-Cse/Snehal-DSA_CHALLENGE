#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
     for(int i=0;i<s.length();i++){
         if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
             st.push(s[i]);
         }
         else if(!st.empty() && s[i]==')' && st.top()=='(' ||
          !st.empty() && s[i]==']' && st.top()=='[' ||
           !st.empty() && s[i]=='}' && st.top()=='{' ){
             st.pop();
         }
         else{
             st.push(s[i]);
         }
     }
        return st.empty();
    }
};