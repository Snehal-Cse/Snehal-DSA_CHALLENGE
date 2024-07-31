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
bool isSymmetricH(TreeNode *left, TreeNode *right){
    if(left==NULL && right==NULL){
        return true;
    }
    if((left == NULL && right !=NULL) || (left !=NULL && right ==NULL)){
        return false;
    }
    if(left->val != right ->val){
        return false;
    }
    return isSymmetricH(left->left, right->right) && isSymmetricH(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
   return isSymmetricH(root->left, root->right);
}

};