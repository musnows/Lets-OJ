class Solution {
    vector<int> retV;
    // 数组转为int
    int vector2int(vector<int>& v) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum = sum * 10 + v[i];
        }
        return sum;
    }

    void _sumNumbers(TreeNode* root, vector<int> curV) {
        if(root == nullptr){
            return; // 空节点不做任何处理
        }
        // 到叶子节点就需要插入了，不然会额外多处理一次
        if (root->right == nullptr && root->left == nullptr) {
            curV.push_back(root->val);        // 叶子节点的值
            retV.push_back(vector2int(curV)); // 插入返回值数组
            return;
        }
        // 前序遍历
        curV.push_back(root->val);
        _sumNumbers(root->left, curV);
        _sumNumbers(root->right, curV);
    }

public:
    int sumNumbers(TreeNode* root) {
        _sumNumbers(root, vector<int>());
        int sum = 0;
        for (auto& i : retV) {
            sum += i;
        }
        return sum;
    }
};
