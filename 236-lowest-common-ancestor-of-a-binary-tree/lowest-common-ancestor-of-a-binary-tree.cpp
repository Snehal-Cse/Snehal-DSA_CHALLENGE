class Solution {
public:
    bool findPath(TreeNode *root, vector<TreeNode*>& path, int val) {
        if (root == NULL) {
            return false;
        }
        path.push_back(root);
        if (root->val == val) {
            return true;
        }
        if (findPath(root->left, path, val) || findPath(root->right, path, val)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        
        if (!findPath(root, path1, p->val) || !findPath(root, path2, q->val)) {
            return NULL;
        }
        
        int i;
        for (i = 0; i < path1.size() && i < path2.size(); i++) {
            if (path1[i] != path2[i]) {
                break;
            }
        }
        
        return path1[i-1];
    }
};