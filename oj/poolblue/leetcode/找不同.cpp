//https://leetcode.cn/problems/find-the-difference/description/
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for (char ch: s) {
            ret ^= ch;
        }
        for (char ch: t) {
            ret ^= ch;
        }
        return ret;
    }
};


