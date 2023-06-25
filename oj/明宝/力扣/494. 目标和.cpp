// 494. 目标和

//https://leetcode.cn/problems/target-sum/description/
// https://www.programmercarl.com/0494.%E7%9B%AE%E6%A0%87%E5%92%8C.html#%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92
class Solution {
public:
// dp[i]代表运算结果为i的方法数
// 设其中有正数和为x，负数和为y（不带符号），x+y = sum(nums),x-y = target
// 联立方程得：x = (sum(nums)+target)/2
// 我们只需要找到有多少种方法可以从数组中选出若干个元素使得它们的和等于(target + sum(nums)) / 2即可
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++) sum+=nums[i];
        if(target>sum || target<0-sum) return 0;
        if((sum+target)%2==1) return 0;
        int bagsize = (sum+target)/2;
        
        vector<int> dp(bagsize+1, 0);
        dp[0] = 1;
        for(int i = 0; i<nums.size(); i++)
        {
            for(int j = bagsize; j>=nums[i]; j--)
            {
                // 可以理解为：我不取第i个数+我取第i个数（第i个数大小为nums[i],我取它之后装满背包，也就是之前的背包里已经装了j-nums[i]）
                dp[j] = dp[j] + dp[j-nums[i]];
            }
        }

        return dp[bagsize];
    }
};
