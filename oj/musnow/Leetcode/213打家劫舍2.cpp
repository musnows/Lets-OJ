class Solution {
public:
    int rob(vector<int>& nums) {
        // 只有一个房子，直接偷
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 0) {
            return 0;
        }
        // 考虑让原始数组不成环，即抛弃第一个，和抛弃最后一个
        // 这时候就不需要考虑环的问题了，求这两种情况的最大值就行了
        int left = _rob(nums, 0, nums.size() - 1);
        int right = _rob(nums, 1, nums.size());
        return max(left, right);
    }
    // 198 的逻辑
    int _rob(vector<int>& nums, int begin, int end) {
        // 区间只有一个元素，直接返回
        if (begin + 1 >= end) {
            return nums[begin];
        }
        // dp[i] 代表包括i下标在内的房子，最多能偷多少钱
        // 1. 不偷i，dp[i] = dp[i-1]
        // 2. 偷i，dp[i] = dp[i-2] + nums[i]
        // 计算这两个值的较大者就可以了
        vector<int> dp(nums.size(), 0);
        // 根据递推公式可得，我们必须初始化dp0和1
        dp[begin] = nums[begin]; // 第一个房间肯定要偷，不偷的情况是0
        // 对比上一个房间和当前房间的价值，如果当前房间更大，则代表不偷上一个房间
        dp[begin + 1] = max(nums[begin + 1], nums[begin]);
        // 从2开始递推
        int maxValue = max(dp[begin], dp[begin + 1]);
        for (int i = begin + 2; i < end; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            maxValue = max(maxValue, dp[i]);
        }
        return maxValue;
    }
};

// https://leetcode.cn/problems/house-robber-ii/