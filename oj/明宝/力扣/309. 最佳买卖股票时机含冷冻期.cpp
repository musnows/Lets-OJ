//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
//309. 最佳买卖股票时机含冷冻期

//https://www.programmercarl.com/0309.%E6%9C%80%E4%BD%B3%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E6%97%B6%E6%9C%BA%E5%90%AB%E5%86%B7%E5%86%BB%E6%9C%9F.html#%E6%80%9D%E8%B7%AF
// 

class Solution {
public:
// 0：持有股票状态（今天买入股票，或者是之前就买入了股票然后没有操作，一直持有）
// 不持有股票状态，这里就有两种卖出股票状态
// 1：保持卖出股票的状态（两天前就卖出了股票，度过一天冷冻期。或者是前一天就是卖出股票状态，一直没操作）
// 2：今天卖出股票
// 3：今天为冷冻期状态，但冷冻期状态不可持续，只有一天！
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp (prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];// 持有股票
        for(int i = 1; i<prices.size(); i++)
        {
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][3], dp[i-1][1])-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0]+prices[i];
            dp[i][3] = dp[i-1][2];
        }
        for(int i = 0; i<prices.size(); i++)
        {
            for(int j = 0; j<4; j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        // 1,2,3状态取最大值
        return max(dp[prices.size()-1][1], max(dp[prices.size()-1][2], dp[prices.size()-1][3]));
    }
};
