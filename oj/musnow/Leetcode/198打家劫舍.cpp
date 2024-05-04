class Solution {
public:
    int rob(vector<int>& nums) {
        // 只有一个房子，直接偷
        if (nums.size() < 2) {
            return nums[0];
        }
        // dp[i] 代表包括i下标在内的房子，最多能偷多少钱
        // 1. 不偷i，dp[i] = dp[i-1]
        // 2. 偷i，dp[i] = dp[i-2] + nums[i]
        // 计算这两个值的较大者就可以了
        vector<int> dp(nums.size(), 0);
        // 根据递推公式可得，我们必须初始化dp0和1
        dp[0] = nums[0]; // 第一个房间肯定要偷，不偷的情况是0
        // 对比上一个房间和当前房间的价值，如果当前房间更大，则代表不偷上一个房间
        dp[1] = max(nums[1], nums[0]);
        // 从2开始递推
        int maxValue = max(dp[0], dp[1]);
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            maxValue = max(maxValue, dp[i]);
        }
        return maxValue;
    }
};
// https://leetcode.cn/problems/house-robber/