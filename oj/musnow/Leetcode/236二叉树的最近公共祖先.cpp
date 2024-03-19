class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // root也可以是它自己的祖先
        if(root == nullptr || root == p || root == q){
            return root;
        }
        // 用后序遍历的思路来处理，这样能找到当前节点的孩子里面有么有q或者p
        TreeNode* left = lowestCommonAncestor(root->left, p,  q);
        TreeNode* right = lowestCommonAncestor(root->right, p,  q);
        // 如果左右都不为空，则代表root就是最近的公共祖先
        if(left != nullptr && right != nullptr){
            return root;
        }
        
        // // // 如果两个都为空，代表没有找到，返回空
        // if(left == nullptr && right == nullptr){
        //     return nullptr;
        // }
        // // 如果有一个为空，则返回另外一个
        // if(left != nullptr && right == nullptr){
        //     return left;
        // }
        // if(left == nullptr && right != nullptr){
        //     return right;
        // }
        // return nullptr; // 这里的返回没有意义，因为不会走到这里来

        // 上面的三个判断可以精简成下面这个
        // 如果left为空且right也为空的时候，本来就需要返回nullptr，此时返回right也是一样的
        return left != nullptr ? left : right;
    }
};


// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/