class Solution {
public:
    void getNext(int* next,const string& s)
    {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i<s.size();i++){
            while(j>0&& s[i] != s[j])
            {
                j = next[j-1];
            }
            if(s[i] == s[j])
            {
                j++;
            }  
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        if(s.size() <= 1)
        {
            return false;
        }

        int next[s.size()+1];
        getNext(next,s);
        int len = s.size();
        // next[len-1] 为0的时候不符合题目条件，但len%(len-0)就为0了
        // 所以必须要先判断next[len-1]是否为0
        if(next[len-1] != 0 && len % (len - next[len-1]) == 0){
            return true;
        }

        return false;
    }
};

// https://leetcode.cn/problems/repeated-substring-pattern/description/
// KMP算法题目