class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 因为求的是最小值，所以数组都初始化为最大值
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // 装满背包0的最少硬币数量是0个
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j < dp.size(); j++) {
                if (dp[j - coins[i]] == INT_MAX) {
                    continue; // 跳过初始值
                }
                // 减去当前金币重量得到的最小硬币个数，加上当前硬币
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// https://leetcode.cn/problems/coin-change/