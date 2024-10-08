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
#include<vector>
class Solution {
public:
  
 vector<int> preorderTraversal(TreeNode* root) {
  vector<int>ans;
     stack<TreeNode *>st;
     st.push(root);
     if(root==NULL){
         return ans;
     }
     while(!st.empty()){
      TreeNode *temp =  st.top();
         st.pop();
         if(temp->right){
             st.push(temp->right);
         }
         if(temp->left){
             st.push(temp->left);
         }
         ans.push_back(temp->val);    
     }
   return ans;
    }
};