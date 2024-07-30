class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
     queue<TreeNode *>q;
     q.push(root);
   
        while(!q.empty()){
            vector<int>level;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                 if(temp->right){
                    q.push(temp->right);
                }
               level.push_back(temp->val);
            }
           ans.push_back(level); 
            
            
        }
     return ans;
    }
};
