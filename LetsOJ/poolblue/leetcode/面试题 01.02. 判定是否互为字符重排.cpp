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
};