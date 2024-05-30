class Solution {
    // 从left和right开始往左右扩展找回文子串，返回值是起始下标和长度
    pair<int, int> findReverseString(const string& s, int left, int right) {
        // 记录
        int len = 1;
        int begin = left;
        // 往两边扩展
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right]) {
                break;
            }
            // 相同，记录长度和开始下标
            len = right - left + 1;
            begin = left;
            // 扩展
            left--;
            right++;
        }
        return {begin, len};
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }
        int maxLength = 1;
        int maxBegin = 0;
        for (int i = 0; i < n; i++) {
            // 偶数情况
            auto [begin, len] = findReverseString(s, i, i + 1);
            // 奇数情况
            auto [begin2, len2] = findReverseString(s, i - 1, i + 1);
            // 如果奇数的结果更长，更新结果
            if (len2 > len) {
                len = len2;
                begin = begin2;
            }
            // 更新最大值
            if (len > maxLength) {
                maxLength = len;
                maxBegin = begin;
            }
        }
        // 返回结果
        return s.substr(maxBegin, maxLength);
    }
};