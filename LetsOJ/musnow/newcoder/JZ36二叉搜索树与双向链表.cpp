/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	// 二叉搜素树的中序遍历是有序的
	void MiddleOrder(TreeNode* root,vector<TreeNode*>& Tree)
	{
		if(root==nullptr)
		{
			return;
		}

		MiddleOrder(root->left,Tree);
		Tree.push_back(root);//插入到数组中
		MiddleOrder(root->right,Tree);
	}

    TreeNode* Convert(TreeNode* pRootOfTree) {
		if(pRootOfTree == nullptr)
		{
			return nullptr;
		}
		vector<TreeNode*> Tree;
        MiddleOrder(pRootOfTree,Tree);
		TreeNode* newTree = Tree[0];//第一个节点
		TreeNode* cur;
		for(int i=0;i<Tree.size();i++)
		{
			cur = Tree[i];
			cur->right = Tree[i+1];
			if (i>0){
				cur->left=Tree[i-1];
			}
		}
		return newTree;
    }
};

//https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking