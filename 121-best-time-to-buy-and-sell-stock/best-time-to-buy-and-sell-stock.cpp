class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int maxi =INT_MIN;
        int buy =INT_MAX;
       for(int i=0;i<n;i++){
          if(prices[i]<buy){
              buy = prices[i];
          }
           maxi = max(maxi, prices[i]-buy);           
       }
        return maxi;
    }
};