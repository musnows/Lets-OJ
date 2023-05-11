//https://leetcode.cn/problems/reverse-string-ii/
//541. 反转字符串 II
class Solution {
public:
    string reverseStr(string s, int k) {
        //每次加2k，在2k的区间进行翻转
     for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
                continue;//到下一个2k区间
            }
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;


    }
};
