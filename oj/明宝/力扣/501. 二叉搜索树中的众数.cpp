// 501. 二叉搜索树中的众数 https://leetcode.cn/problems/find-mode-in-binary-search-tree/
// https://www.programmercarl.com/0501.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E4%BC%97%E6%95%B0.html 
    TreeNode* pre = NULL;
    int count = 0;
    int maxCount = 0;
    vector<int> v;
    void traversal(TreeNode* root)
    {
        if(root == NULL) return;

        traversal(root->left);

        if(pre == NULL)// first
            count = 1;
        else if(root->val == pre->val)// equal
            count++;
        else// new number
            count = 1;

        if(count==maxCount)
            v.push_back(root->val);// 放入众数
        if(count>maxCount)
        {
            maxCount = count;// update maxCount!!!
            v.clear();// 清空原本的值
            v.push_back(root->val);// 放入新的目前的众数
        }

        pre = root;// update pre

        traversal(root->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return v;
    }
