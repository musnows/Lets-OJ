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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;//存放节点指针
        vector<int> v;//存放返回值
        TreeNode* cur = root;
        while(cur || !st.empty())
        {
            while(cur)
            {
                v.push_back(cur->val);
                st.push(cur);
                cur=cur->left;
            }
            //出了循环代表cur已经走到了最左边
            //获取栈顶节点，即为该节点的上一个位置
            TreeNode* top=st.top();//这里直接更新cur也可以
            st.pop();
            //访问该节点的右子树
            cur=top->right;
        }
        
        return v;
    }
};

//144前序遍历（迭代）
//https://leetcode.cn/problems/binary-tree-preorder-traversal/submissions/
