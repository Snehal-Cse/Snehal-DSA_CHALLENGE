class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
       int m = board.size();
       int n = board[0].size();
        vector<pair<int,int>>v;
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               int ones =0;
                if(i-1>=0 && j-1>=0){
                    ones+=board[i-1][j-1];
                }
               if(i-1>=0){
                   ones+=board[i-1][j];
               }
               if(i-1>=0 && j+1<n){
                   ones+=board[i-1][j+1];
               }
               if(j+1<n){
                   ones+=board[i][j+1];
               }
               if(i+1<m && j+1<n){
                   ones+=board[i+1][j+1];
               }
               if(i+1<m){
                   ones+=board[i+1][j];
               }if(i+1<m && j-1>=0){
                   ones+=board[i+1][j-1];
               }if(j-1>=0){
                   ones+=board[i][j-1];
               }
               if(board[i][j]==1){
                   if(ones<2){
                       v.push_back({i,j});
                   }
                   else if(ones>3){
                       v.push_back({i,j});
                   }
               }
               else{
                   if(ones==3){
                        v.push_back({i,j});
                   }
                    
               }  
           }
       } 
        for(int i=0;i<v.size();i++){
            int x = v[i].first;
            int y = v[i].second;
            board[x][y] ^=1;
        }
    }
};