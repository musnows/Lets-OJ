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
    TreeNode* _buildTree(const vector<int>& inorder,int inorderBegin,int inorderEnd,const vector<int>& postorder,int postorderBegin,int postorderEnd) {
        // 递归分治条件
        // if(inorder.size() == 0 || postorder.size() == 0){
        //     return nullptr;
        // }
        
        if(inorderBegin>=inorderEnd || postorderBegin >= postorderEnd){
            return nullptr;
        }

        // 后序遍历的最后一个节点是根节点
        // int val = postorder[postorder.size()-1];
        int val = postorder[postorderEnd-1];
        TreeNode* root = new TreeNode(val);

        // 在中序遍历数组中找到这个值，注意题目保证节点值不重复，所以能这么做。
        int i = 0; // 提前定义，后面要用
        // for(i = 0;i<inorder.size();i++)
        for(i = inorderBegin;i<inorderEnd;i++)
        {
            if(inorder[i] == val){
                break;
            }
        }

        // 拆中序数组，使用[0,i)区间
        // vector<int> inorderLeft(inorder.begin(),inorder.begin()+i);
        int inorderBeginLeft = inorderBegin;
        int inorderEndLeft = inorderBegin+(i-inorderBegin); // 如果直接加i是错误的，i已经是下标了，再加会超出范围

        // 下面这里是[i+1,end)区间，必须额外加一，否则不符合条件
        // vector<int> inorderRight(inorder.begin()+i+1,inorder.end()); 
        int inorderBeginRight = inorderBegin+(i-inorderBegin)+1; // 这里需要加一，是跳过被选中的中间节点
        int inorderEndRight = inorderEnd;

        // 拆后续数组，因为后续数组的大小肯定和中序一致，从前往后拆就分别对应中序的左数组和右数组了
        // 将后续遍历数组中的的最后一个值删掉，因为当前已经使用了
        // postorder.resize(postorder.size()-1); 

        // 这里inorderLeft.size()理论上和i是相同的，所以用i也没问题
        // [0,inorderLeft.size())
        // vector<int> postorderLeft(postorder.begin(),postorder.begin()+inorderLeft.size());
        int postorderBeginLeft = postorderBegin;
        int postorderEndLeft = postorderBegin + (i - inorderBegin);

        // [inorderLeft.size(),end())
        // vector<int> postorderRight(postorder.begin()+inorderLeft.size(),postorder.end());
        int postorderBeginRight = postorderBegin + (i - inorderBegin); // 这里不需要加一，因为中间没有多出来一个数
        int postorderEndRight = postorderEnd -1; // 排除最后一个节点

        // 递归遍历
        TreeNode* left = _buildTree(inorder,inorderBeginLeft,inorderEndLeft,postorder,postorderBeginLeft,postorderEndLeft);
        TreeNode* right = _buildTree(inorder,inorderBeginRight,inorderEndRight,postorder,postorderBeginRight,postorderEndRight);
        // 链接
        root->left = left;
        root->right = right;
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0){
            return nullptr;
        }
        return _buildTree(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
};


// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/