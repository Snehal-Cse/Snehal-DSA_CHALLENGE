#include<stack>
class Solution {
public:
    int calculate(string s) {
      stack<int>st;
    
      char op='+';
      int currentNum;
        for(int i=0;i<s.length();i++){
           if(isdigit(s[i])){
               currentNum = currentNum*10 + (s[i]-'0');
           }
           if(!isdigit(s[i]) && !isspace(s[i]) || i==s.length()-1){
               if(op == '+'){
                   st.push(currentNum);
               }
               else if(op == '-'){
                   st.push(-currentNum);
               }
               else if(op == '*'){
                   int stTop = st.top();
                   st.pop();
                   st.push(stTop*currentNum);
               }
               else if(op == '/'){
                   int stTop = st.top();
                   st.pop();
                   st.push(stTop/currentNum);
               }
               op = s[i];
               currentNum = 0;
           }
        }
        int result =0;
        while(!st.empty()){
           int a = st.top();
            st.pop();
            result += a;
        }
        return result;
        
    }
};