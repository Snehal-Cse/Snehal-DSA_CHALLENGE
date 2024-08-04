class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>in;
        for(int i=1;i<=size;i++){
              TreeNode *temp = q.front();
              q.pop();
           
           if(temp!=NULL && temp->left!=NULL){
                q.push(temp->left); 
           }
            if(temp!=NULL &&  temp->right !=NULL){
              q.push(temp->right); 
            }
           
            if(temp!=NULL) {
                in.push_back(temp->val);
            }
          } 
          ans.push_back(in);
        }
        return ans;
    }
};
