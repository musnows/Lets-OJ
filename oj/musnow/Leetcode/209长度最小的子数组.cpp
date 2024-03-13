class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0,right=0; // 滑动窗口
        int minRange = INT32_MAX; // 因为需要获取最小值，所以要用一个最大值来比较
        int sum = 0;
        for(right =0;right<nums.size();right++)
        {
            sum += nums[right];
            while(sum >= target) // 这里必须要用while，需要考虑right是最后一个但left还可以继续走的情况
            {
                //cout << "fix: " << left << " - " << right << " sum:" << sum << "\n";
                int curDiff = right - left + 1; // 当前长度
                minRange = min(minRange,curDiff);
                sum -= nums[left];
                left ++;// 左侧缩限
            }
            //cout << "all: " << left << " - " << right << " sum:" << sum << "\n";
        }
        // 如果还是最大值，则返回0
        return minRange == INT32_MAX ? 0 : minRange;
    }
};

// https://leetcode.cn/problems/minimum-size-subarray-sum/description/
// 滑动窗口典型例题
// 代码随想录 https://www.programmercarl.com/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.html#%E6%80%9D%E8%B7%AF