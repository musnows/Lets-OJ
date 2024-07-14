class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += subStringExtend(s, i, i, s.size());     // 奇数
            result += subStringExtend(s, i, i + 1, s.size()); // 偶数
        }
        return result;
    }
    // 从left/right开始往两头扩展，返回最长回文子串长度
    // 分为二者相等（奇数长度）二者不等（偶数长度）的情况
    int subStringExtend(const string& s, int left, int right, int end) {
        int result = 0; // 字符自己也认为是一个长度
        while (left >= 0 && right < end && s[left] == s[right]) {
            left--;
            right++;
            // 结果长度
            result++;
        }
        return result;
    }
};
