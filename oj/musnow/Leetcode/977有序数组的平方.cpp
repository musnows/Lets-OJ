class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0,right=nums.size()-1;// 遍历源数组
        int k = nums.size()-1;// 插入新数组
        vector<int> retV;
        retV.resize(nums.size()); // 不能用reserve

        // 必须闭区间，因为left==right的时候是最后一个数字
        while(left<=right && k>=0)
        {
            int doubleLeft = nums[left] * nums[left];
            int doubleRight = nums[right] * nums[right];
            // cout << doubleLeft << "  " << doubleRight << "\n";
            if(doubleLeft > doubleRight)
            {
                retV[k--] = doubleLeft;
                left++;
            }
            else
            {
                retV[k--] = doubleRight;
                right--;
            }
        }
        return retV;
    }
};

// https://leetcode.cn/problems/squares-of-a-sorted-array/
