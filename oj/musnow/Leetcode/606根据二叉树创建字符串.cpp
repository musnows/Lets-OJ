//https://leetcode.cn/problems/construct-string-from-binary-tree/
//606. 根据二叉树创建字符串

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
    //使用引用传址，一直操作的是同一个str，减小深拷贝消耗
    void _tree2str(TreeNode* root,string& str)
    {
        if(root==nullptr){
            return;
        }
        //前序遍历
        str+=to_string(root->val);

        //如果左不为空，进行递归插入
        if(root->left)
        {
            str+='(';
            _tree2str(root->left,str);
            str+=')';
        }
        //左为空但是右不为空，插入空括号
        else if(root->right){
            str+="()";
        }
        //右边不为空才执行插入操作        
        if(root->right){
            str+='(';
            _tree2str(root->right,str);
            str+=')';
        }
    }
    //主函数
    string tree2str(TreeNode* root) {
        string str;
        _tree2str(root,str);
        return str;
    }
};