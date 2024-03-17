class Solution {
    // 查找最大值，返回最大值的下标
    int searchMaxIndex(const vector<int>& nums,int begin,int end){
        int maxNum = nums[begin];
        int maxNumIndex = begin;
        for(int i = begin;i<end;i++)
        {
            if(nums[i] > maxNum){
                maxNum = nums[i];
                maxNumIndex = i;
            }
        }
        return maxNumIndex;
    }

    TreeNode* _constructMaximumBinaryTree(const vector<int>& nums,int begin,int end){
        // 本题采用左闭右开，所以begin==end是无效区间
        if(nums.size() == 0 || begin>=end){
            return nullptr;
        }
        // 找到最大值的下标
        int maxNumIndex = searchMaxIndex(nums,begin,end);
        TreeNode* root = new TreeNode(nums[maxNumIndex]);
        // 左右拆分
        int leftBegin = begin;
        int leftEnd = maxNumIndex; 

        int rightBegin = maxNumIndex+1; // 加一跳过当前选中节点
        int rightEnd = end;

        root->left = _constructMaximumBinaryTree(nums,leftBegin,leftEnd);
        root->right = _constructMaximumBinaryTree(nums,rightBegin,rightEnd);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0){
            return nullptr;
        }
        return _constructMaximumBinaryTree(nums,0,nums.size());
    }
};

// https://leetcode.cn/problems/maximum-binary-tree/