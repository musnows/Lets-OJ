class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> retV;
        if(root == nullptr){
            return retV;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            int maxNum = INT32_MIN;
            for(int i =0;i< size;i++)
            {
                TreeNode* temp = que.front();
                que.pop();
                maxNum = max(maxNum,temp->val);
                
                if(temp->left != nullptr){
                    que.push(temp->left);
                }
                if(temp->right != nullptr){
                    que.push(temp->right);
                }
            }
            retV.push_back(maxNum);
        }
        return retV;
    }
};

// https://leetcode.cn/problems/find-largest-value-in-each-tree-row/