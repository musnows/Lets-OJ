//https://leetcode.cn/problems/check-permutation-lcci/submissions/
//面试题 01.02. 判定是否互为字符重排
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
     if(s1.size()!=s2.size())
      return false;
     sort(s1.begin(),s1.end());
     sort(s2.begin(),s2.end());
      return s1==s2;
    }
};\
//哈希 
//由于字符串只包含 2626 个小写字母，因此我们可以维护一个长度为 2626 的频次数组 \textit{table}table，
//先遍历记录字符串 s 1中字符出现的频次，然后遍历字符串 s_2s 
//减去 able 中对应的频次，如果出现 table[i]<0则说明 s 2包含一个不在 s1中的额外字符，返回 false 即可
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        vector<int> table(26, 0);
        for (auto& ch: s1) {
            table[ch - 'a']++;
        }
        for (auto& ch: s2) {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

