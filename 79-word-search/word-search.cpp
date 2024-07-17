#include<vector>
class Solution {
public:
    bool isValid(vector<vector<char>>&board, string &word, int i, int j, int wordIndex, vector<vector<int>>&vis){
        int m = board.size();
        int n = board[0].size();
        if(i>=0 && i<m && j>=0 && j<n && board[i][j]== word[wordIndex] && vis[i][j]==0){
            return true;
        }
        return false;
    }
    bool f(vector<vector<char>>&board, string &word, int i, int j, int wordIndex, vector<vector<int>>&vis){
        int len = word.length();
        if(wordIndex>len-1){
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        int di[4] = {-1, 0, 1, 0};
        int dj[4]= {0,1,0,-1};
        if(!isValid(board, word, i, j, wordIndex, vis)){
            return false;
        }
        vis[i][j]= 1;
        for(int k=0;k<4;k++){
            int newI = i + di[k];
            int newJ = j+dj[k];
            if(f(board, word, newI, newJ, wordIndex+1, vis)){
                return true;
            }
        }
        vis[i][j]=0;
      return false;  
    }

    bool exist(vector<vector<char>>& board, string word) {
      int m = board.size();
      int n = board[0].size();
      vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(f(board, word, i, j, 0, vis)){
                    return true;
                }
            }
           
        } 
         return false;
    }
};
