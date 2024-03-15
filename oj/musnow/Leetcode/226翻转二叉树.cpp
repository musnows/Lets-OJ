class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* front = que.front();
            que.pop();
            swap(front->left,front->right);

            // 虽然这里可以不用写不等于空，但是写上可读性更好。
            if(front->left != nullptr){
                que.push(front->left);
            }
            if(front->right != nullptr){
                que.push(front->right);
            }

        }
        return root;
    }
};

// https://leetcode.cn/problems/invert-binary-tree/