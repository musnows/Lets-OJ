#define _CRT_SECURE_NO_WARNINGS 1


//144. 二叉树的前序遍历
//https://leetcode-cn.com/problems/binary-tree-preorder-traversal/submissions/
//// 二叉树节点个数
//void BTreeSize(struct TreeNode* root, int* pcount)
//{
//	if (root == NULL)
//		return;
//
//	(*pcount)++;
//	BTreeSize(root->left, pcount);
//	BTreeSize(root->right, pcount);
//
//}
//// 前序遍历代码
//void BTreePrevOrder(struct TreeNode* root, int* arr, int* i)
//{
//	if (root == NULL) {
//		return;
//	}
//
//	arr[(*i)++] = root->val;
//	//因为在递归调用中需要多次调用不同的i，所以需要取地址
//	BTreePrevOrder(root->left, arr, i);
//	BTreePrevOrder(root->right, arr, i);
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//	int count = 0;
//	BTreeSize(root, &count);//计算树节点个数
//	int* arr = (int*)malloc(sizeof(int) * count);//开辟数组
//
//	int i = 0;//下标
//	BTreePrevOrder(root, arr, &i);
//	*returnSize = count;
//	return arr;
//}

//94二叉树中序遍历
//https://leetcode-cn.com/problems/binary-tree-inorder-traversal/submissions/
//145. 二叉树的后序遍历
//https://leetcode-cn.com/problems/binary-tree-postorder-traversal/submissions/
//只需要更改数组位置就可以了！




//100. 相同的树
//https://leetcode-cn.com/problems/same-tree/
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)//比较是否两个节点都为空，都为空是真
//        return true;
//
//    if (p == NULL || q == NULL)//如果有一个为空，另外一个非空，即为假
//        return false;
//
//    if (p->val != q->val)//都不是空，判断val的值是否相等
//        return false;
//
//    //递归判断左子树和右子树是否相等
//    return isSameTree(p->left, q->left)
//        && isSameTree(p->right, q->right);
//}


//101. 对称二叉树
//https://leetcode-cn.com/problems/symmetric-tree/
// 
//bool _isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)//比较是否两个节点都为空，都为空是真
//        return true;
//
//    if (p == NULL || q == NULL)//如果有一个为空，另外一个非空，即为假
//        return false;
//
//    if (p->val != q->val)//都不是空，判断val的值是否相等
//        return false;
//
//    //递归判断左子树和右子树是否对称相等
//    return _isSameTree(p->left, q->right)
//        && _isSameTree(p->right, q->left);
//}
//
//bool isSymmetric(struct TreeNode* root) {
//    return _isSameTree(root->left, root->right);
//}



//572. 另一棵树的子树
//https://leetcode-cn.com/problems/subtree-of-another-tree/submissions/
//bool _isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)//比较是否两个节点都为空，都为空是真
//        return true;
//
//    if (p == NULL || q == NULL)//如果有一个为空，另外一个非空，即为假
//        return false;
//
//    if (p->val != q->val)//都不是空，判断val的值是否相等
//        return false;
//
//    //递归判断左子树和右子树是否相等
//    return _isSameTree(p->left, q->left)
//        && _isSameTree(p->right, q->right);
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    // if(root==NULL&&subRoot==NULL)
//    //     return true;
//    //让isSametree函数来比较这俩个
//    // if(root!=NULL&&subRoot==NULL)
//    //     return true;
//
//    if (root == NULL)
//        return false;
//
//    if (_isSameTree(root, subRoot))
//        return true;
//
//    //只要左右有一个是返回真，那就是子树
//    return isSubtree(root->left, subRoot)
//        || isSubtree(root->right, subRoot);
//}


//翻转二叉树
//https://leetcode-cn.com/problems/invert-binary-tree/
//void _invertTree(struct TreeNode* root)
//{
//    if (root == NULL)//设置退出条件，如果根节点为空就返回
//        return;
//
//    //让另外两个值来接收原本的左右节点
//    struct TreeNode* left = root->left;
//    struct TreeNode* right = root->right;
//
//    //更改左右节点
//    root->right = left;
//    root->left = right;
//
//    //递归子树
//    _invertTree(root->left);
//    _invertTree(root->right);
//}
//
//struct TreeNode* invertTree(struct TreeNode* root) {
//    if (root == NULL)//判断空树
//        return NULL;
//
//    _invertTree(root);
//
//    return root;
//}


//KY11 二叉树遍历
//https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//
//typedef char BTDataType;
//
//typedef struct BTreeNode
//{
//    BTDataType data;
//    struct BTreeNode* left;
//    struct BTreeNode* right;
//}BTNode;
//
//// 二叉树中序遍历 
//void BTreeInOrder(BTNode* root)
//{
//    if (root == NULL) {
//        return;
//    }
//
//    BTreeInOrder(root->left);
//    printf("%c ", root->data);
//    BTreeInOrder(root->right);
//}
//
//BTNode* CreatTree(char* arr, int* i)
//{
//    if (arr[*i] == '#') {
//        (*i)++;
//        return NULL;
//    }
//
//    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
//    if (newnode == NULL)
//    {
//        printf("malloc failed\n");
//        exit(-1);
//    }
//
//    newnode->data = arr[(*i)++];
//    newnode->left = CreatTree(arr, i);
//    newnode->right = CreatTree(arr, i);
//
//    return newnode;
//}
//
//int main()
//{
//    char arr[100];
//    scanf("%s", arr);
//
//    int i = 0;
//    BTNode* root = CreatTree(arr, &i);
//    BTreeInOrder(root);
//    return 0;
//}


//102. 二叉树的层序遍历
//https://leetcode-cn.com/problems/binary-tree-level-order-traversal/submissions/
//这道题写了题解，看自己的博客！

//#define MAX 2000
//int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
//    if (root == NULL)
//        return;
//
//    struct TreeNode* Queue[MAX];//队列，存放节点的地址
//    int front = 0, tail = 0;//指向队头和队尾
//
//    *returnSize = 0;//将二叉树层级初始化为0
//    int** ret = (int**)malloc(sizeof(int*) * MAX);//存放二叉树的每一层节点的值
//    *returnColumnSizes = (int*)malloc(sizeof(int*) * (MAX / 2));//开辟一个数组来存放每一层的节点个数
//
//    struct TreeNode* head;
//    Queue[tail++] = root;//根节点入队
//    while (front != tail)
//    {
//        int Csize = 0;//每一层的节点个数
//        int end = tail;//end是每一层最末一个节点的指针。在后续的入队列操作中tail会改变，所以需要保存tail的值
//        ret[*returnSize] = (int*)malloc(sizeof(int*) * (end - front));//为每一层开辟一个单独的数组来存放值
//        while (front < end)
//        {
//            head = Queue[front++];
//            ret[*returnSize][Csize++] = head->val;
//            if (head->left != NULL)
//                Queue[tail++] = head->left;
//            if (head->right != NULL)
//                Queue[tail++] = head->right;
//        }
//        (*returnColumnSizes)[*returnSize] = Csize;//得到每一层的节点数量
//        (*returnSize)++;//层数+1
//    }
//
//    return ret;
//}