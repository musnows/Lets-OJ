class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> retV;
        if(root == nullptr){
            return retV;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            for(int i = 0;i < size;i++)
            {
                TreeNode* front = que.front();
                que.pop();
                // 每一层的末尾才插入数组
                if(i == size-1){
                    retV.push_back(front->val);
                }

                if(front->left != nullptr){
                    que.push(front->left);
                }
                if(front->right != nullptr){
                    que.push(front->right);
                }
            }
        }
        return retV;
    }
};