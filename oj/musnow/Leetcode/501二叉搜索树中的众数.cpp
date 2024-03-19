class Solution {
    int maxCount = -1; // 计数器肯定是正的，初始化为负数即可
    int count = 0; // 这里不能用count作为参数，因为每一层的修改对全局都是有效的
    TreeNode* prev = nullptr;
    
    void inordereTravelCount(TreeNode* root,vector<int>& retV)
    {
        if(root == nullptr){
            return;
        }
        // 左
        inordereTravelCount(root->left,retV);
        // 中，计数
        if(prev == nullptr)// 第一个节点
        {
            count = 1;
        }
        else if(prev->val == root->val) // 相同
        {
            count++;
        }
        else // 不相同，新的节点
        {
            count = 1;
        }
        prev = root;

        // 和当前记录最大值相同，插入        
        if(count == maxCount)
        {
            retV.push_back(root->val);
        }
        // 超过了最大记录，需要清空返回值数组
        else if(count > maxCount){
            maxCount = count;
            retV.clear();
            retV.push_back(root->val);
        }

        inordereTravelCount(root->right,retV);
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> retV;
        inordereTravelCount(root,retV);
        return retV;
    }
};


// https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/