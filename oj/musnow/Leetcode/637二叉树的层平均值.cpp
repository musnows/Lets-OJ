class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> retV;
        if(root == nullptr){
            return retV;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            double sum = 0;
            for(int i = 0;i < size;i++)
            {
                TreeNode* front = que.front();
                que.pop();
                // 求和
                sum += front->val;

                if(front->left != nullptr){
                    que.push(front->left);
                }
                if(front->right != nullptr){
                    que.push(front->right);
                }
            }
            // 一层结束。计算平均
            retV.push_back(sum/static_cast<double>(size*1.0));
        }
        return retV;
    }
};

// https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/