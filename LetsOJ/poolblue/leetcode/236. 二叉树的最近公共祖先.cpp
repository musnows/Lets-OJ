//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
// 236. 二叉树的最近公共祖先
//第一种思路 ：普通二叉树遍历 
class Solution {
public:
    bool IsInSubTree(TreeNode* tree, TreeNode* x)
    {
        if(tree==nullptr)//树为空 
        return false;
        if(tree==x)//找到结点 
        return true;

        return  IsInSubTree(tree->left,x)//继续遍历左右子树 
            ||  IsInSubTree(tree->right,x);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)//树为空 
        return nullptr;
        if(p==root ||q==root)//p 和q任意一个是根节点，就是最近祖先 
        return root;

        bool pinleft=IsInSubTree(root->left,p);//遍历左子树找p 
        bool pinright=!pinleft;

        bool  qinleft=IsInSubTree(root->left,q);//遍历右子树找q 
        bool qinright =!qinleft;

        if((qinleft &&pinright)||(qinright && pinleft) )//q和p各自在左右子树，则root为最近祖先 
         return root;

         else if(qinleft &&pinleft)//都在左子树，继续递归遍历 
         return lowestCommonAncestor(root->left,p,q);

        else if(qinright &&pinright)//都在右子树，继续递归遍历 
          return lowestCommonAncestor(root->right ,p,q);

        else
           return nullptr;
    }
};

