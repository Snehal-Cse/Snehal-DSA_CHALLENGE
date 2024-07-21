class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        stack<char>st2;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && s[i]=='#'){
                st.pop();
            }
            else if(s[i]!='#'){
                st.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(!st2.empty() && t[i]=='#'){
                st2.pop();
            }
            
            else if(t[i]!='#'){
                st2.push(t[i]);
            }
        }
        string new1 = "";
        string new2 = "";
        while(!st.empty()){
                if(new1.empty()){
                 new1 =st.top();   
                }
            else{
                 new1 =st.top()+ new1;
            }          
            st.pop();
        }
        while(!st2.empty()){
          if(new2.empty()){
              new2 = st2.top();
          } 
            else{
                 new2 =st2.top()+ new2;
            }
         
            st2.pop();
        }
        return new1 == new2;
    }
};