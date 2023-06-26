//518. 零钱兑换 II

//https://leetcode.cn/problems/coin-change-ii/description/
// https://www.programmercarl.com/0518.%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2II.html#%E6%80%9D%E8%B7%AF
class Solution {
public:
// 因为每种面额的硬币有无限个，所以是完全背包问题
// 如果求组合数就是外层for循环遍历物品，内层for遍历背包。
// 如果求排列数就是外层for遍历背包，内层for循环遍历物品。

//https://www.bilibili.com/video/BV1KM411k75j/?vd_source=3ad2a62940718859702ce089b46d5288
// b站视频下评论区：先遍历物品后遍历背包是这样，比如，外层循环固定coins【1】，在内层循环遍历背包时，随着背包不断增加，coins【1】可以重复被添加进来，而由于外层循环固定了，
//因此coins【2】只能在下一次外层循环添加进不同大小的背包中，这么看的话，coins【i+1】只能在coins【i】之后了；
//如果先遍历背包后遍历物品，那么外层循环先固定背包大小j，然后在大小为j的背包中循环遍历添加物品，然后在下次外层循环背包大小变为j+1，
//此时仍要执行内层循环遍历添加物品，也就会出现在上一轮外层循环中添加coins【2】的基础上还能再添加coins【1】的情况，那么就有了coins【1】在coins【2】之后的情况了。

// dp[i]表示总金额为i的所有方法
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0; i<coins.size(); i++)// 遍历物品
        {
            for(int j = coins[i]; j<=amount; j++)// 遍历背包容量
            {
                dp[j] += dp[j-coins[i]];
            }
            // for(int k = 0; k<amount+1; k++)
            //     cout<<dp[k]<<" ";
            // cout<<endl;
        }
        // for (int j = 0; j <= amount; j++) { // 遍历背包容量
        //     for (int i = 0; i < coins.size(); i++) { // 遍历物品
        //         if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
        //     }
        //     for(int k = 0; k<amount+1; k++)
        //         cout<<dp[k]<<" ";
        //     cout<<endl;
        // }
        return dp[amount];
    }
};
