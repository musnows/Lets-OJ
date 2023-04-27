//https://leetcode.cn/problems/compress-string-lcci/
//面试题 01.06. 字符串压缩 
//双指针遍历 
class Solution {
public:
    string compressString(string S) {
       int i = 0, j = 0, ls = S.length();
        string res;
        while (i < ls) {
            while (j < ls && S[i] == S[j])
                j++;
            res += S[i];
            res += to_string(j - i);
            i = j;
        }
        return res.length() < ls ? res : S;
   

    }
};
