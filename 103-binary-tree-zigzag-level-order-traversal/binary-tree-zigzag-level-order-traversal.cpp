/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>ans;
         if(root==NULL){
            return ans;
        }
       queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
          int size = q.size();
             vector<int>in;
          for(int i=0;i<size;i++){
              TreeNode *temp = q.front();
              q.pop();
              if(temp->left!=NULL){
                    q.push(temp->left);
              }
              if(temp->right!=NULL){
                   q.push(temp->right);
              }
              in.push_back(temp->val); 
          }
           if(ans.size()%2!=0){
              reverse(in.begin(), in.end());
           } 
            ans.push_back(in);
        }
        return ans;
    }
};