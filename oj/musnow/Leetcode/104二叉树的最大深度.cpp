class Solution {
public:
    int maxDepth(TreeNode* root) {
        int retDepth = 0;
        if(root == nullptr){
            return retDepth;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            retDepth++; // 层数加一
            for(int i =0;i< size;i++)
            {
                TreeNode* temp = que.front();
                que.pop();
                
                if(temp->left != nullptr){
                    que.push(temp->left);
                }
                if(temp->right != nullptr){
                    que.push(temp->right);
                }
            }
        }
        return retDepth;
    }
};