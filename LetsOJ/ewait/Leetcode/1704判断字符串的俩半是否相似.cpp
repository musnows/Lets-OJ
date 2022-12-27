class Solution {
public:
    bool halvesAreAlike(string s) {
        string cmp = "aeiouAEIOU";
        int sz = s.size();
        int count1=0,count2=0;
        for(int i=0;i<sz/2;i++)
        {
            for(auto&c:cmp)
            {
                if(s[i]==c)
                {
                    count1++;
                }
                if(s[i+sz/2]==c)
                {
                    count2++;
                }
            }
        }
        //cout << count1 << " " <<count2<<endl;
        return count1==count2;
    }
};
//https://leetcode.cn/problems/determine-if-string-halves-are-alike/description/
