class Solution {
public:
    bool isValid(int col, vector<string>&board, int n, int row){
        int dupRow = row;
        int dupCol = col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row = dupRow;
        col = dupCol;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row = dupRow;
        col = dupCol;
        while(col>=0 && row<n){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void f(int col, vector<vector<string>>&ans, vector<string>&board, int n){
         if(col>=n){
             ans.push_back(board);
             return;
         }
        for(int i=0;i<n;i++){
            if(isValid(col, board, n, i)){
                board[i][col]='Q';
                f(col+1, ans, board, n);
                board[i][col]='.';
            }
        }
    }
  
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));
        int col =0;
        f(col, ans, board, n);
        return ans;
    }
};