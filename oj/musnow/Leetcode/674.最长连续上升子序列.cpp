class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ret = 1; // 结果长度
        int cur = 1; // 当前的长度
        // 从1开始遍历，因为0只有一个元素，没有意义
        for (int i = 1; i < nums.size(); i++) {
            // 因为要求连续，所以只需要判断前一位就够了。
            if (nums[i] > nums[i - 1]) {
                cur = cur + 1;
            } else {
                cur = 1; // 其他情况，重置为1，重新开始计算
            }
            // 更新结果最大值
            if (cur > ret) {
                ret = cur;
            }
        }
        return ret;
    }
};
