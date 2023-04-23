//https://leetcode.cn/problems/letter-case-permutation/ 
class Solution {
public:
   void dfs(string &s,int pos,vector<string>& res)
    {   //回溯法
        while(pos<s.size() && isdigit(s[pos]))//对字符串遍历，如果是数字，则继续++
        {
            pos++;
        }
        if(pos==s.size())
        {
         res.push_back(s);
         return;
        }

        s[pos] ^=32;//变换大小写
        dfs(s,pos+1,res);
         s[pos] ^=32;//变换大小写
        dfs(s,pos+1,res);
      
    }
    vector<string> letterCasePermutation(string s) {
    vector<string> res;
    dfs(s,0,res);

    return res;
    }
};
