/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void _inOrder(struct TreeNode* root,int*arr)
{
    if(root==NULL){
        return;
    }
    //printf("%d ",root->val);
    arr[root->val]++;//下标映射
    _inOrder(root->left,arr);
    _inOrder(root->right,arr);
    return ;
}


int numColor(struct TreeNode* root){
    int sz=1001;
    int* arr=(int*)calloc(sz,sizeof(int));
    _inOrder(root,arr);//中序遍历
    int i =0,count=0;
    for(i=0;i<sz;i++){
        if(arr[i]!=0){
            count++;
        }
    }
    //printf("count- %d",count);
    return count;
}
//LCP 44. 开幕式焰火
//https://leetcode.cn/problems/sZ59z6/
// 执行用时：8 ms, 在所有 C 提交中击败了85.11%的用户
// 内存消耗：9.1 MB, 在所有 C 提交中击败了14.90%的用户