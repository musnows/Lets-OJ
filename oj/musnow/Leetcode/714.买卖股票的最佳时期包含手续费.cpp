class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 0) {
            return 0;
        }
        vector<vector<int>> dp(2, vector<int>(2, 0));
        // 第一天持有
        dp[0][0] = 0 - prices[0];
        // 开始遍历
        for (int i = 1; i < prices.size(); i++) {
            // 1.今天买入
            // 2.昨天开始就持有了
            dp[1][0] = max(dp[0][0], dp[0][1] - prices[i]);
            // 1.今天卖出（需要交手续费）
            // 2.昨天开始就不持有了
            dp[1][1] = max(dp[0][1], dp[0][0] + prices[i] - fee);
            // 把今天的数值挪过昨天去
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }
        return dp[1][1];
    }
};
