class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        // 当k==2的时候一共有五种状态，状态总数是2k+1
        // 除了第一个状态（下标0）的时候是啥事不干
        // 其余的状态奇数是当前第n次持有，偶数是当前第n次持有
        vector<vector<int>> dp(prices.size(), vector<int>(k * 2 + 1, 0));
        // 遍历，将奇数都初始化为当前买入的初始值
        for (int j = 1; j < dp[0].size(); j += 2) {
            // 当前的第n次买入
            dp[0][j] = 0 - prices[0];
        }
        // 开始完整遍历
        for (int i = 1; i < prices.size(); i++) {
            // 当天啥事不干
            dp[i][0] = dp[i - 1][0];
            // 开始遍历k
            for (int j = 1; j < dp[i].size(); j++) {
                if (j % 2 == 1) {
                    // 奇数，买入
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                } else {
                    // 偶数，卖出
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                }
            }
        }
        // 最后一个肯定是最大钱的时候
        return dp[prices.size() - 1][2 * k];
    }
};
