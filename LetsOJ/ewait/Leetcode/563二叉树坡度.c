/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


typedef struct TreeNode Node;
//计算左右子树值的和
int _Sumofval(Node* root)
{
    if (root == NULL)
        return 0;

    return root->val +
        _Sumofval(root->left)+
        _Sumofval(root->right);
}
//再来二次递归
void _DiffVal(Node* root,int* sum)
{
    if(root==NULL)
        return;
    
    int lh = _Sumofval(root->left);
    int rh = _Sumofval(root->right);
    int diff = abs(lh-rh);//左右子树值的差
    //printf("%d ",diff);
    (*sum)+=diff;

    _DiffVal(root->left,sum);
    _DiffVal(root->right,sum);
    return;
}

int findTilt(struct TreeNode* root){
    int sum = 0;
    _DiffVal(root,&sum);
    return sum;
}


//https://leetcode.cn/problems/binary-tree-tilt/
//563. 二叉树的坡度
