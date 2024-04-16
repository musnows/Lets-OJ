class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        // 从后往前遍历
        int start = s.size() + 1; // 初始化为不会进入第二个循环的值
        for (int i = s.size() - 1; i >= 1; i--) {
            // 对于ascii来说也是增加的，所以可以直接判断
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                start = i; // 从这一位开始设置9
            }
        }
        // 从start开始遍历，设置9，注意x99999也视作递增序列
        for (int i = start; i < s.size(); i++) {
            s[i] = '9';
        }
        return atoi(s.c_str());
    }
};
