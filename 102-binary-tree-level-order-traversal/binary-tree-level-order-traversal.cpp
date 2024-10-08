class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>v;
            for(int i=0;i<size;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
               v.push_back(temp->val);
            }
            ans.push_back(v); 
        }
        return ans;
    }
};
