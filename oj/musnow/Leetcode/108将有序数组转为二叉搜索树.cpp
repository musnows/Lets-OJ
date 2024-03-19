class Solution {
    TreeNode* _sortedArrayToBST(const vector<int>& nums,int left,int right) {
        if(left >= right){
            return nullptr;
        }
        int mid = left + ((right - left)/2); 
        
        // int mid = (right - left)/2; // 这样计算的结果是错误的，值可能会小于left，导致陷入死循环

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = _sortedArrayToBST(nums,left,mid);
        root->right = _sortedArrayToBST(nums,mid+1,right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return nullptr;
        }
        return _sortedArrayToBST(nums,0,nums.size());
    }
};

// https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/submissions/513819078/