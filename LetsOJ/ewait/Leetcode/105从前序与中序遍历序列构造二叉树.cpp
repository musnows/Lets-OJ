tion for a binary tree node.
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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,
                        int& prev,int inbegin,int inend)
    {
        if(inbegin>inend){//中序区间不存在
            return nullptr;
        }

        TreeNode* root= new TreeNode(preorder[prev]);
        prev++;//指向下一个待构建的根节点

        //区间如下，rooti为中线
        //[inbegin, rooti-1] rooti [rooti+1,inend]
        int rooti = inbegin;//开始找区间中线的位置
        while(rooti<=inend)
        {
            if(root->val == inorder[rooti])
                break;
            else
                rooti++;
        }

        //[inbegin, rooti-1] rooti [rooti+1,inend]
        root->left =_buildTree(preorder,inorder,prev,inbegin,rooti-1);
        root->right =_buildTree(preorder,inorder,prev,rooti+1,inend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //参数说明：
        //prev是当前需要构建的根节点的位置
        //inbegin是中序区间的开始，inend是中序区间的结束
        int prev=0,inbegin=0,inend=inorder.size()-1;
        //不能使用无符号整型作为参数，因为有需要比较0和-1的情况！
        TreeNode* ret=_buildTree(preorder,inorder,prev,inbegin,inend);
        return ret;
    }
};
