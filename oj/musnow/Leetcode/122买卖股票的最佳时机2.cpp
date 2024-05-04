class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = 0;
        // 第0天买，第3天卖的利润是prices[3]-prices[0]
        // 也等于 p[3]-p[2] + p[2]-p[1] + p[1]-p[0]
        // 所以最大利润其实就是每天利润之和（前提是利润都是正的）
        for (int i = 1; i < prices.size(); i++) {
            // 计算昨天买今天卖能获得多少利润
            // 如果大于0就加入进去
            count += max(prices[i] - prices[i - 1], 0);
        }
        return count;
    }
};

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            // 1.今天买入股票的剩余钱需要计算上一天卖出后剩下的最多钱
            // 2.今天不买入，沿用上一天的结果
            dp[1][0] = max(dp[0][1] - prices[i], dp[0][0]);
            // 1.今天卖出股票，得到的钱是上一天买入股票剩余价值+今天卖出的价格
            // 2.今天不卖出股票，沿用上一天的结果
            dp[1][1] = max(prices[i] + dp[0][0], dp[0][1]);
            // 把当前值挪过去，作为上一行的结果
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }
        return dp[1][1];
    }
};