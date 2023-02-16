/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;//存放节点指针
        vector<int> v;//存放返回值
        TreeNode* cur = root;
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
            //出了循环代表cur已经走到了最左边
            //获取栈顶节点，即为该节点的上一个位置
            TreeNode* top=st.top();
            st.pop();
            //出栈代表左路节点已经走完，可以走根
            v.push_back(top->val);

            //访问该节点的右子树
            cur=top->right;
        }
        
        return v;
    }
};

//94中序遍历（迭代）
//https://leetcode.cn/problems/binary-tree-inorder-traversal/
