//1049. 最后一块石头的重量 II
//https://leetcode.cn/problems/last-stone-weight-ii/description/
// https://www.programmercarl.com/1049.%E6%9C%80%E5%90%8E%E4%B8%80%E5%9D%97%E7%9F%B3%E5%A4%B4%E7%9A%84%E9%87%8D%E9%87%8FII.html#%E6%80%9D%E8%B7%AF

class Solution {
public:
// 01背包
// 最后dp[target]里是容量为target的背包所能背的最大重量。
// 那么分成两堆石头，一堆石头的总重量是dp[target]，另一堆就是sum - dp[target]。
// 在计算target的时候，target = sum / 2 因为是向下取整，所以sum - dp[target] 一定是大于等于dp[target]的。
// 那么相撞之后剩下的最小石头重量就是 (sum - dp[target]) - dp[target]。
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i = 0; i<stones.size(); i++)
            sum+=stones[i];

        int target = sum/2;
        vector<int> dp(1501, 0);
        for(int i = 0; i<stones.size(); i++)
        {
            for(int j = target; j>=stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
            }
        }

        return sum-2*dp[target];
    }
};
