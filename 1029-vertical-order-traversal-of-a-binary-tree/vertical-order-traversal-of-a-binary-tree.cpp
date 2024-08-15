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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      vector<vector<int>>ans;
        map<int, map<int, multiset<int>>>mp;
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root, {0,0}});
        while(!q.empty()){
            TreeNode *node = q.front().first;
            int ver = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            mp[ver][level].insert(node->val);
            if(node->left){
                q.push({node->left, {ver-1, level+1}});
            }
           if(node->right){
                q.push({node->right, {ver+1, level+1}});
            } 

        }
        for(auto x : mp){
            vector<int>col;
            for(auto y : x.second){
                col.insert(col.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
        
    }
};