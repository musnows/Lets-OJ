class Solution {
public:
    int _isBalanced(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        // 使用后续遍历，如果有一个不符合预期就提前返回
        int left = _isBalanced(root->left);
        if(left == -1){
            return -1;
        }
        int right = _isBalanced(root->right);
        if(right == -1){
            return -1;
        }
        // 都不是负一，计算节点高度插值
        if(abs(right -left)>1){
            return -1;// 超过1了不符合
        }
        else{
            return 1 + max(right,left); // 返回高的那一个作为当前树的高度
        }
    }

    bool isBalanced(TreeNode* root) {
        return _isBalanced(root) == -1 ? false : true;
    }
};
