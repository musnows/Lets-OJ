class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        // 一共有4种状态
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = 0 - prices[0];
        for (int i = 1; i < prices.size(); i++) {
            // 今天持有股票，要么是昨天就买了，要么是今天才买
            // 昨天就已经持有的情况是沿用过去的状态dp[i-1][0]
            // 今天才买的情况一是昨天保持卖出股票的情况
            // 还有一种情况是昨天是冷冻期，那么我们今天买股票要用的是冷冻期状态的钱
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][2] - prices[i],
                                             dp[i - 1][3] - prices[i]));
            // 今天卖出，代表昨天是持有股票的情况
            dp[i][1] = dp[i - 1][0] + prices[i];
            // 昨天是冷冻期
            // 前天就卖出了，还没有买入，维持不持有的状态
            dp[i][2] = max(dp[i - 1][3], dp[i - 1][2]);
            // 冷冻期只可能是昨天卖出股票了
            dp[i][3] = dp[i - 1][1];
        }
        // 最大值只会出现后三种情况中
        return max(dp[prices.size() - 1][1],
                   max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
    }
};
