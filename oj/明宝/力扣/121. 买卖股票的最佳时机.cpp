// 121. 买卖股票的最佳时机

//https://www.programmercarl.com/0121.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA.html#%E6%80%9D%E8%B7%AF
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
// dp[i][0]代表第i天持有这支股票
// dp[i][1]代表第i天不持有这支股票
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i<len; i++)
        {
//如果第i天持有股票即dp[i][0]， 那么可以由两个状态推出来
// 第i-1天就持有股票，那么就保持现状，所得现金就是昨天持有股票的所得现金 即：dp[i - 1][0]
// 第i天买入股票，所得现金就是买入今天的股票后所得现金即：-prices[i]
            dp[i][0] = max(dp[i-1][0], -prices[i]);
// 如果第i天不持有股票即dp[i][1]， 也可以由两个状态推出来
// 第i-1天就不持有股票，那么就保持现状，所得现金就是昨天不持有股票的所得现金 即：dp[i - 1][1]
// 第i天卖出股票，所得现金就是按照今天股票价格卖出后所得现金即：prices[i] + dp[i - 1][0]
            dp[i][1] = max(dp[i-1][0]+prices[i], dp[i-1][1]);
        }
        return dp[len-1][1];
    }
};
