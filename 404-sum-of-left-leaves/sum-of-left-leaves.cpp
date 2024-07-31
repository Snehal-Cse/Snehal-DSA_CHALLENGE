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
    int sum =0;
   bool isLeftNode(TreeNode *root){
        if(root==NULL){
            return false;
        }
       if(root->left ==NULL && root->right==NULL){
           return true;
       }
       return false;
    }
    void f(TreeNode *root){
        if(root ==NULL){
            return ;
        }
       if(isLeftNode(root->left)){
           sum+=root->left->val;
       }
        f(root->left);
        f(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL || root->left ==NULL && root->right==NULL){
            return 0;
        }
       f(root);
        return sum;
        
        
        
    }
};