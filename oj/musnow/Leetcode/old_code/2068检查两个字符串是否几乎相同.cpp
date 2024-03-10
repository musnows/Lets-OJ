class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> cmp1(26,0);
        vector<int> cmp2(26,0);
        for(auto &c:word1)
        {
            cmp1[c-'a']++;
        }
        for(auto &c:word2)
        {
            cmp2[c-'a']++;
        }

        for(int i=0;i<cmp1.size();i++)
        {
            if(abs(cmp1[i]-cmp2[i])>=4)
            {
                return false;
            }
        }
        return true;
    }
};
//https://leetcode.cn/problems/check-whether-two-strings-are-almost-equivalent/description/
