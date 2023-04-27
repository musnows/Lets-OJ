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
    //leetcode102层序遍历
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> vv;
		if (root == nullptr)
			return vv;

		queue<TreeNode*> q;
		int levelSize = 1;
		q.push(root);

		while (!q.empty())
		{
			// levelSize控制一层一层出
			vector<int> levelV;
			while (levelSize--)
			{
				TreeNode* front = q.front();
				q.pop();
				levelV.push_back(front->val);
				if (front->left)
					q.push(front->left);

				if (front->right)
					q.push(front->right);
			}
			vv.push_back(levelV);
			// 上一层出完，下一层就都进队列
			levelSize = q.size();

            for (auto e : levelV)
			{
				cout << e << " ";
			}
			cout << endl;
		}

		return vv;
	}
    bool isEvenOddTree(TreeNode* root) {
        if(root==nullptr){
            return false;
        }
        vector<vector<int>> vv=levelOrder(root);
        if((vv[0][0])%2!=1)//第0层必须要是奇数
            return false;

        
        for(int i = 1;i<vv.size();i++)
        {
            vector<int> lv = vv[i];
            //先在外层判断每一层第一个的奇偶性
            if(i%2==0 && lv[0]%2!=1){
                return false;
            }
            else if(i%2==1 && lv[0]%2!=0)
            {
                return false;
            }
            //再从第二个数据开始循环，判断奇偶性和递增递减
            for(int j = 1;j<lv.size();j++)
			{
                //判断奇偶
                if(i%2==0 && lv[j]%2!=1){
                    return false;
                }
                else if(i%2==1 && lv[j]%2!=0)
                {
                    return false;
                }
                //判断是否严格递增
				if(i%2==0 && lv[j-1]>=lv[j]){
                    return false;
                }
                else if(i%2==1 && lv[j-1]<=lv[j])
                {
                    return false;
                }               
			}
            //因为如果从第0个开始，到size()-1，就会落掉最后一个的奇偶性判断
        }
        return true;
    }
};

// 如果一棵二叉树满足下述几个条件，则可以称为 奇偶树 ：

// 二叉树根节点所在层下标为 0 ，根的子节点所在层下标为 1 ，根的孙节点所在层下标为 2 ，依此类推。
// 偶数下标 层上的所有节点的值都是 奇 整数，从左到右按顺序 严格递增
// 奇数下标 层上的所有节点的值都是 偶 整数，从左到右按顺序 严格递减
// 给你二叉树的根节点，如果二叉树为 奇偶树 ，则返回 true ，否则返回 false 。

// 来源：力扣（LeetCode）1609. 奇偶树
// 链接：https://leetcode.cn/problems/even-odd-tree