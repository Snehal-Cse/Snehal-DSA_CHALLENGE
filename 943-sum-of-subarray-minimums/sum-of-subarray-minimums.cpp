class Solution {
public:
     vector<int>findPrev(vector<int>&arr, int n){
        vector<int>ans(n, -1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>= arr[i]){
                st.pop();
            }
           if(!st.empty()){
               ans[i] = st.top();
           }
            st.push(i);
        }
        return ans; 
     }
    vector<int>findNext(vector<int>&arr, int n){
        vector<int>ans(n, n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]> arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1000000007;
        int n = arr.size();
       vector<int>prev = findPrev(arr,n);
        vector<int>next = findNext(arr,n);
        long long total =0;
        for(int i=0; i<arr.size();i++){
        int a = next[i]-i;
        int b = i - prev[i];
        total = (total + (long long)(a * b % mod) * arr[i] % mod) % mod;  
        }  
      return total;
    }
};