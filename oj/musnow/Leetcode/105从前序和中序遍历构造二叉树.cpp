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
    TreeNode* _buildTree(const vector<int>& preorder,int preorderBegin,int preorderEnd,const  vector<int>& inorder, int inorderBegin,int inorderEnd)
    {
        // 递归返回条件
        if(inorderBegin >= inorderEnd || preorderBegin >= preorderEnd){
            return nullptr;
        }
        // 前序遍历的第一个
        int val = preorder[preorderBegin];
        TreeNode* root = new TreeNode(val);

        // 在中序遍历数组中找
        int i =0;
        for(i = inorderBegin;i<inorderEnd;i++){
            if(inorder[i] == val){
                break;
            }
        }

        // 拆分中序遍历数组
        int offset = i-inorderBegin;
        // 左侧数组[inorderBegin,inorderBegin+offset)
        int inorderBeginLeft = inorderBegin;
        int inorderEndLeft = inorderBegin + offset;  // 这里不能直接加i，应该加i和开头的偏移量
        // 右侧数组[inorderBegin+offset+1,inorderEnd)
        int inorderBeginRight = inorderBegin + offset+1;
        int inorderEndRight = inorderEnd;

        // 拆分前序遍历数组
        // 左侧数组[preorderBegin+1,preorderBegin+1+offset)，开头需要加一跳过第一个值
        int preorderBeginLeft = preorderBegin+1;
        int preorderEndLeft = preorderBegin+1+offset;
        // 右侧数组[preorderBegin+1+offset,preorderEnd)
        int preorderBeginRight = preorderBegin+1+offset;
        int preorderEndRight = preorderEnd;

        // 递归遍历
        TreeNode* left = _buildTree(preorder,preorderBeginLeft,preorderEndLeft,inorder,inorderBeginLeft,inorderEndLeft);
        TreeNode* right = _buildTree(preorder,preorderBeginRight,preorderEndRight,inorder,inorderBeginRight,inorderEndRight);
        // 链接
        root->left = left;
        root->right = right;
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0){
            return nullptr;
        }
        return _buildTree(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
};

// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/