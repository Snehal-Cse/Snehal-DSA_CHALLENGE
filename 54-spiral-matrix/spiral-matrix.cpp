class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sr = 0;
        int sc = 0;
        int lr = m-1;
        int lc = n-1;
        vector<int>ans;
        while(sr<=lr && sc<=lc){
        for(int j=sc;j<=lc && sr<=lr && sc<=lc  ;j++){
            ans.push_back(matrix[sr][j]);
        }
        sr++;
        for(int j = sr; j<=lr && sr<=lr && sc<=lc ;j++){
            ans.push_back(matrix[j][lc]);
        }
        lc--;
        for(int j=lc; j>=sc && sr<=lr && sc<=lc; j--){
            ans.push_back(matrix[lr][j]);
        }
        lr--;
        for(int j=lr; j>=sr && sr<=lr && sc<=lc; j--){
            ans.push_back(matrix[j][sc]);
        }
        sc++;
        }
        return ans;
    }
};