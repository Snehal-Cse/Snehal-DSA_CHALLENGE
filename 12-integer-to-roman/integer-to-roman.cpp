class Solution {
public:
    string intToRoman(int num) {
       string ones[10] = {"", "I", "II", "III", "IV", "V","VI","VII","VIII", "IX"};
       string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
       string huns[10]= {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thous[4]= {"", "M", "MM", "MMM"};
        return thous[num/1000] + huns[(num%1000)/100] + tens[(num%100)/10] + ones[(num%10)];
        
        
    }
};