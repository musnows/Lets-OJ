//337. 打家劫舍 III

//https://leetcode.cn/problems/house-robber-iii/description/
//https://www.programmercarl.com/0337.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8DIII.html#%E6%80%9D%E8%B7%AF 
 
class Solution {
public:
// 树形dp，dp[0]代表偷本节点的最大值，dp[1]代表不偷本节点的最大值
    int rob(TreeNode* root) {
        vector<int>res = robTree(root);
        return max(res[0], res[1]);
    }
    // 0：偷 1：不偷
    vector<int> robTree(TreeNode* cur)
    {
        if(cur==nullptr) return {0, 0};
        // 上层要用下层的数据，所以后序遍历
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷cur，那么就不能偷左右节点。
        int num0 = cur->val + left[1] + right[1];
        // 不偷cur，那么可以偷也可以不偷左右节点，则取较大的情况
        int num1 = max(left[0], left[1]) + max(right[0], right[1]);
        return {num0, num1};
    }
};
