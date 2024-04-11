class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            // 原有公式 ret * 10 + x % 10 <= INT_MAX
            // 修补一下 ret * 10 + x % 10 <= (INT_MAX/10)*10 + INT_MAX%10
            // 移动一下 (ret - INT_MAX/10)*10 <= INT_MAX % 10 - X % 10
            // 需要判断不等式成立的条件
            // ret如果比INT_MAX/10小，说明末尾的个位数还没有达到INT_MAX的顶置，此时可以选择0到9
            // ret如何和INT_MAX/10相等，说明末尾只能选择小于等于7的值，否则越界
            int temp = abs(ret);
            if ((temp > INT_MAX / 10) || (temp == INT_MAX / 10 && x % 10 > 7)) {
                return 0;
            } 
            // 如果越界了，这个公式是无法计算成功的
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret;
    }
};

// https://leetcode.cn/problems/reverse-integer/