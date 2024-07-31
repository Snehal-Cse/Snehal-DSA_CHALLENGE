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
    void preOrder(TreeNode *root, string &str){
        if (root) {
            str += "," + to_string(root->val);
            preOrder(root->left, str);
            preOrder(root->right, str);
        } else {
            str += ",#"; // Append a special character for null pointers
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1;
         preOrder(root, s1);
        string s2 ;
        preOrder(subRoot, s2);
        return s1.contains(s2);
    }
};