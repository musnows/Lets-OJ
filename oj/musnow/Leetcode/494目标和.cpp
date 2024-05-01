class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto&i:nums){
            sum+=i;
        }
        // 如果target的绝对值大于sum，那么说明全加都不能达到这个数
        if(abs(target)>sum){
            return false;
        }
        // 数组拆成两部分，left+right=sum
        // right = sum - left; sum = left + (sum-left)
        // 只要target小于sum，那么就一定会有左边组合减去右边组合等于target
        // 含义是左半部分是+的，后半部分是-的，组合起来就等于target
        // target = left - right; 
        // 继续推导公式
        // left = target + right = target + sum - left 
        // left = (sum + target)/2; 得到这个左半部分的公式
        // 我们现在需要求的就是有多少种组合可以达到左半部分
        // 就等同于给你一个容量为left的背包，有几种方式可以将背包装满
        int left = (sum + target)/2;
        // 不能整除，无法拆成两个部分的差值，不符合条件
        if((target + sum)%2 == 1){
            return false;
        }
        vector<int> dp(left+1,0);
        // 不管是什么情况，都肯定会有一种方式能到达target
        // dp 0 的含义是 有几种方法可以得到左半边部分为0，我们不装东西，就是左半部分为0了
        // left不装东西，本质上是在所有数字前面加-号，所以只有一种方式
        dp[0] = 1; 
        for(int i = 0;i<nums.size();i++)
        {
            // 从最大值开始一直递推回容量等于当前数的时候
            for(int j = dp.size()-1;j>=nums[i];j--){
                // 假设当前nums[i] = 2，那么就有dp[j-2]的方式装满这个书包
                // 注意会有很多种不同的结果，需要累加
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[left];
    }
};