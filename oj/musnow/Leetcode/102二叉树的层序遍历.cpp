//https://leetcode.cn/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        
        if(root==nullptr){
            return vv;//空树
        }

        int levelSize=1;//从1开始
        queue<TreeNode*> q;//存放节点指针
        q.push(root);
        while(!q.empty())
        {
            vector<int> levelV;//存放每一层数据的vector
            while(levelSize--)
            {
                TreeNode* cur=q.front();
                q.pop();
                levelV.push_back(cur->val);//把队列中的节点值入vector

                //左右不为空的时候才执行入队列
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
                
            }
            levelSize=q.size();//执行完一层后，队列的大小就是下一层的节点数量
            vv.push_back(levelV);//将本层结果插入最终的返回值vv
        }

        return vv;
    }
};



