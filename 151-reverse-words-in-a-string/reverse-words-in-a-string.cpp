#include<stack>
class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string res;
        for(int i=0;i<s.length();i++){
            string temp ="";
            while(i < s.length() && s[i]!=' '){
                temp += s[i];
                i++;
            }
            if(!temp.empty()){
                st.push(temp);
            }
            if(s[i]==' '){
                continue;
            }
        }
        while(!st.empty()){
            if(res.empty()){
                res = st.top();
            }
            else{
            res = res +" "+ st.top();
            }
            st.pop();
        }
        return res;
    }
};
