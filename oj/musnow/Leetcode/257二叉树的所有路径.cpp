class Solution {
public:
    // 字符串不能传引用，不然下层的更改会影响上层
    void binaryTreePaths(TreeNode* root,string curStr,vector<string>& retV)
    {
        // // 到空节点了就插入到数组中
        // if(root == nullptr){
        //     // 删除多余的->
        //     retV.push_back(curStr.substr(0,curStr.size()-2));
        //     return;
        // }

        // 上面的思路错误，如果某个节点有左子树或右子树，此时就会多插入一个无效的路径
        // 正确思路是空节点不处理
        if(root == nullptr){
            return ;
        }
        // 到叶子节点了就直接插入到数组中
        if(root->left == nullptr && root->right == nullptr){
            curStr +=  to_string(root->val);
            retV.push_back(curStr); // 不需要删除多余的->
            return ;
        }

        // 前序遍历
        curStr += to_string(root->val);
        curStr += "->";
        binaryTreePaths(root->left,curStr,retV);
        binaryTreePaths(root->right,curStr,retV);
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> retV;
        binaryTreePaths(root,"",retV);
        return retV;
    }
};

// https://leetcode.cn/problems/binary-tree-paths/