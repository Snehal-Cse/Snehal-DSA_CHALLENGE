class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber){
            columnNumber--;
            char val = columnNumber%26 + 'A';
            ans =  val + ans;
            columnNumber = columnNumber/26;
        }
        return ans;
    }
};