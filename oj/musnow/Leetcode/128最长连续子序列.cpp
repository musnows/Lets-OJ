class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> maps(nums.begin(),nums.end());
        int retCount = 0;
        for(auto&e:nums)
        {
            if(maps.count(e-1)){
                continue;// 上一位存在，代表当前元素处理过了，跳过
            }
            // 找下一位，找到了就继续找
            int count = 1;
            int cur = e;
            while(maps.count(cur+1)){
                count++;
                cur++;
            }
            // 结束后更新最大值
            retCount = max(retCount,count);
        }
        return retCount;
    }
};
// https://leetcode.cn/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-100-liked
