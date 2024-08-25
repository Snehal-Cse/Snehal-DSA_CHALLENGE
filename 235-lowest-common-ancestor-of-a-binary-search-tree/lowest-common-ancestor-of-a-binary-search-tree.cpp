/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool lca1(TreeNode *root, vector<int>&arr1, int x){
        if(root==NULL){
            return false;
        }
        arr1.push_back(root->val);
        if(root->val == x){
            return true;
        }
        if(lca1(root->left, arr1, x) || lca1(root->right, arr1, x)){
            return true;
        }
        arr1.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x = p->val;
        int y = q->val;
        vector<int>arr1;
        vector<int>arr2;
        lca1(root, arr1,  x);
        lca1(root, arr2, y );
        int i =0;
        for(i=0;i<arr1.size() && i<arr2.size() ; i++){
            if(arr1[i]!=arr2[i]){
                break;
            }
        }
       TreeNode *newNode = new TreeNode(arr1[i-1]);
        return newNode;
    }
};