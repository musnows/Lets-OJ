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
    int sumRootToLeaf(TreeNode* root) {
        if (!root) //空
            return 0;

        queue<TreeNode*> nodeque;
        queue<int> numque;

        nodeque.push(root);
        numque.push(root->val);
        int sum = 0;
        while (!nodeque.empty()) {
            TreeNode* cur = nodeque.front(); 
            nodeque.pop();
            int num = numque.front();//上一个路径
            numque.pop();
            //cur的左右为空
            if (!cur->left && !cur->right) {
                sum += num;//加入当前节点的值
            }
            //cur的左不为空
            if (cur->left) {
                nodeque.push(cur->left);//左节点入队列
                //把当前的num左移1位，和左节点的值按位|可以得到一个值
                //比如当前节点值是1
                //左移一位变成10
                //按位与上左节点，此时最后一位即为左节点的值
                //如左节点为1，那么结果就是11
                //以此类推
                numque.push((num << 1) | (cur->left->val));
            }
            //cur的右不为空
            if (cur->right){
                nodeque.push(cur->right);//右节点入队列
                //同上
                numque.push((num << 1) | (cur->right->val));
            }
        }
        return sum;
    }
};
//https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/
//1022. 从根到叶的二进制数之和
