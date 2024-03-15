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
        vector<vector<int>> retV;
        if(root == nullptr){
            return retV;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> tempV;
            for(int i = 0;i < size;i++)
            {
                TreeNode* front = que.front();
                que.pop();
                tempV.push_back(front->val);
                if(front->left != nullptr){
                    que.push(front->left);
                }
                if(front->right != nullptr){
                    que.push(front->right);
                }
            }
            retV.push_back(tempV); // 一层结束
        }
        return retV;
    }
};