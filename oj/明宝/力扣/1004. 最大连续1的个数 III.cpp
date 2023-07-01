//1004. 最大连续1的个数 III

// https://leetcode.cn/problems/max-consecutive-ones-iii/description/
class Solution {
public:
// 题目转化为：找出一个最长的子数组，该子数组内最多允许有 K 个 0 
    int longestOnes(vector<int>& nums, int k) {
        int res=0, zeros=0, left=0;
        for(int right=0; right<nums.size(); right++)
        {
            if(nums[right]==0)
                zeros++;
            while(zeros>k)
            {
                if(nums[left++]==0)
                    zeros--;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};
