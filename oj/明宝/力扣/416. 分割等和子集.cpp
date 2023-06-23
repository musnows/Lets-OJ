//416. 分割等和子集

//https://leetcode.cn/problems/partition-equal-subset-sum/description/
// https://www.programmercarl.com/0416.%E5%88%86%E5%89%B2%E7%AD%89%E5%92%8C%E5%AD%90%E9%9B%86.html#_416-%E5%88%86%E5%89%B2%E7%AD%89%E5%92%8C%E5%AD%90%E9%9B%86
class Solution {
public:
// 用01背包思路做
// dp[i]表示容量为i能装下的最大物品价值，其中物品容量和价值一致，为数组元素
// 本题就变成：先算出数组和的一半，设这个为target；用01背包来获得dp[target]，看看它的值是否==target（这代表着它能否和为target）
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++)
            sum+=nums[i];

        if(sum%2==1) return false;
        int target = sum/2;
        // 总和不会大于20000，背包最大只需要其中一半，所以10001大小就可以了
        vector<int>dp (10001, 0);
        for(int i = 0; i<nums.size(); i++)
        {
            for(int j = target; j>=nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
            }
        }

        if(dp[target]==target)
            return true;
        
        return false;

    }
};
