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
    bool f(TreeNode* root, int target){
        if(target == 0 && root->left == NULL && root->right == NULL){
            return true;
        }
         if(target != 0 && root->left == NULL && root->right == NULL){
            return false;
        }
        return (root->left && f(root->left, target-root->left->val)) ||  (root->right && f(root->right, target-root->right->val)) ;
     
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
     if(root == NULL ){
         return false;
     }
        
        targetSum = targetSum-root->val;
        return f(root, targetSum);  
    }
};

