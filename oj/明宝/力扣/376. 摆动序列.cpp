//376. 摆动序列

//https://leetcode.cn/problems/wiggle-subsequence/
// https://www.programmercarl.com/0376.%E6%91%86%E5%8A%A8%E5%BA%8F%E5%88%97.html#%E6%80%9D%E8%B7%AF-1-%E8%B4%AA%E5%BF%83%E8%A7%A3%E6%B3%95

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int preDiff = 0; 
        int curDiff = 0;
        int result = 1;// 记录峰值个数，序列默认序列最右边有一个峰值
        for(int i = 0; i<nums.size()-1; i++)
        {
            curDiff = nums[i+1] - nums[i];
            if((preDiff>=0 && curDiff<0) || (preDiff<=0 && curDiff>0))
            {
                result++;

                preDiff = curDiff;// 解决情况三：单调坡度有平坡，所以放在判断峰值的时候才更新
            }
        }
        return result;
    }
};
