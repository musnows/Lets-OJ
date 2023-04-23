class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        // 使用滑动窗口的思路
        int left =0,right=0;
        int sum = 0;
        int length = INT32_MAX;// 设置为最大值
        for(right=0;right<nums.size();right++)
        {
            sum+=nums[right];
            //如果大于target，左边界缩小
            while(sum>=target)
            {
                int diff = right-left+1;//长度
                length = length<diff?length:diff;//求最小长度
                sum-=nums[left++];//剪掉左边界
            }
        }
        return length!=INT32_MAX?length:0;//如果长度还是没变，则返回0
    }
};
//https://leetcode.cn/problems/minimum-size-subarray-sum/submissions/