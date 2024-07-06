class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        // dp数组[0]代表i和i之前乘机为正数/负数的最长子数组长度
        vector<int> pos(nums.size(), 0); // 正数
        vector<int> neg(nums.size(), 0); // 负数
        // 第一个元素需要初始化，如果是正数初始化为1，负数初始化为0
        pos[0] = nums[0] > 0 ? 1 : 0;
        neg[0] = nums[0] < 0 ? 1 : 0;
        // 开始遍历
        int maxLength = pos[0]; // 结果集，注意初始化
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                // 到i这里就必须中断了，因为0不能和他们乘
                pos[i] = neg[i] = 0;
            } else if (nums[i] > 0) {
                // 正数，判断正负数的子数组能不能扩张
                pos[i] = pos[i - 1] + 1; // 正数子数组肯定能扩张
                // 当前是正数，需要判断之前有没有乘机为负的子数组（长度不为0），有才能扩张
                neg[i] = neg[i - 1] != 0 ? neg[i - 1] + 1 : 0;
            } else if (nums[i] < 0) {
                // 当前是负数
                // 注意负数子数组长度，要从正数的子数组取数进行扩张，而不是从负数的子数组里面取
                neg[i] = pos[i - 1] + 1;
                // 正数子数组要判断前一位是否存在乘机为负数的子数组
                pos[i] = neg[i - 1] != 0 ? neg[i - 1] + 1 : 0;
            }
            if (pos[i] > maxLength) {
                maxLength = pos[i];
            }
        }
        // 最终返回的就是乘机为正数的最长子数组长度。
        return maxLength;
    }
};
