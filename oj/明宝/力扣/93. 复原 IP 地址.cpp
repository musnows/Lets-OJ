//93. 复原 IP 地址
//https://leetcode.cn/problems/restore-ip-addresses/description/ 
//https://www.programmercarl.com/0093.%E5%A4%8D%E5%8E%9FIP%E5%9C%B0%E5%9D%80.html#%E5%88%A4%E6%96%AD%E5%AD%90%E4%B8%B2%E6%98%AF%E5%90%A6%E5%90%88%E6%B3%95
class Solution {
public:
    vector<string> result;
    void backtracking(string s, int startIndex, int pointNum)
    {
        if(pointNum == 3)
        {
            if(isValid(s, startIndex, s.size()-1))
            {
                result.push_back(s);
            }
            return;
        }
        for(int i = startIndex; i<s.size(); i++)
        {
            if(isValid(s, startIndex, i))
            {
                s.insert(s.begin()+i+1, '.');
                backtracking(s, i+2, pointNum+1);// 注意是+2
                s.erase(s.begin()+i+1);
            }
            else
                break;// 跳出本层

        }
    }
    bool isValid(string s, int start, int end)
    {
        if(start>end)
            return false;
        if(s[start]=='0'&&start!=end)// 0
            return false;
        int sum = 0;
        for(int i = start; i<=end; i++)
        {
            if(s[i]>'9'||s[i]<'0') // 合法字符
                return false;
            sum = sum*10+s[i]-'0';
            if(sum>255) // 整数大小
                return false;
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return result;
    }
};
