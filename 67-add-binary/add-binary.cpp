class Solution {
public:
    string addBinary(string a, string b) {
      int i  = a.length()-1;
        int sum =0;
        int carry =0;
      int j = b.length()-1;
        string ans="";
      while(i>=0 && j>=0){
          int num1 = a[i]-'0';
          int num2 = b[j]-'0';
          sum = num1 + num2 + carry;
          int val = sum%2;
          carry = sum/2;
          char val2 = val + '0';
          ans = val2 + ans;
          i--;
          j--;
      }  
        while(i>=0){
             int num1 = a[i]-'0';
              sum = num1 + carry;
              int val = sum%2;
              carry = sum/2;
              char val2 = val + '0';
              ans = val2 + ans;
               i--;    
        }
        while(j>=0){
              int num2 = b[j]-'0';
              sum = num2 + carry;
              int val = sum%2;
              carry = sum/2;
              char val2 = val + '0';
              ans = val2 + ans;
               j--;    
        }
        if(carry){
           char carry2 = carry+'0';
            ans = carry2 + ans;
        }
        
        return ans;
        
    }
};