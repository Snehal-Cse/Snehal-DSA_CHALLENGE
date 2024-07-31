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
    void f(vector<string>&ans, string s, TreeNode *root){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
            return;
        }
        if(root->left!=NULL){
            f(ans, s + "->"+ to_string(root->left->val), root->left);
        }
        if(root->right!=NULL){
              f(ans, s + "->"+ to_string(root->right->val), root->right);
        }
      
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root==NULL){
            return ans;
        }
        
        f(ans, to_string(root->val), root); 
        return ans;
    }
};