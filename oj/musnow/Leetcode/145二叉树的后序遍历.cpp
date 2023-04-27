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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;//存放节点指针
        vector<int> v;//存放返回值
        TreeNode* cur = root;
        TreeNode* prev = nullptr;//用于存放上一个访问的节点
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
            
            //出栈代表左路节点已经走完，可以走右子树
            //1，右子树为空，直接走根
            //2. 右子树不为空，但是prev（上一个访问的节点）是右子树
            //   说明右子树已经访问过了，可以走根
            //3，右子树不为空，且prev的右子树和top的右不相等，继续走右子树
            if(top->right==prev||top->right==nullptr)
            {
                v.push_back(top->val);
                st.pop();
                
                prev=top;//更新prev
            }
            else{
                //访问该节点的右子树
                cur=top->right;
            }
            
        }
        
        return v;
    }

    
};


//145. 二叉树的后序遍历
//https://leetcode.cn/problems/binary-tree-postorder-traversal/
