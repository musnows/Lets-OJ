class Solution {
public:
    int maxPower(string s) {
        int max = 1;//不管什么情况都会有一个字母满足本题条件
        for(int i=0;i<s.size();i++)
        {
            int count = 0;
            if(s[i]==s[i+1])
            {
                while(s[i]==s[i+1])
                {
                    count++;
                    i++;
                }
                if(count!=0)
                    count++;//不等于0代表有连续字符串，此时会少算一个字母

                //更新max
                max = count>max?count:max;
            }
        }

        return max;
    }
};

//https://leetcode.cn/problems/consecutive-characters/description/
