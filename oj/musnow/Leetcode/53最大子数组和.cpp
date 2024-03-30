class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0;         // 之前的最大子数组和
        int maxNum = nums[0]; // 随便初始化一个值
        for (auto& i : nums) {
            // 如果之前的最大子数组和还没有我自己大，则从我自己开始新列一个子数组
            prev = max(prev + i, i);
            // 更新最大值
            maxNum = max(maxNum, prev);
        }
        return maxNum;
    }
};

// https://leetcode.cn/problems/maximum-subarray/