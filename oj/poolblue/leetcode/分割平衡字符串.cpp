//https://leetcode.cn/problems/split-a-string-in-balanced-strings/description/
class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, d = 0;
        for (char ch : s) {
            ch == 'L' ? ++d : --d;
            if (d == 0) {
                ++ans;
            }
        }
        return ans;
    }
};

