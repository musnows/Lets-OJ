class Solution
{
    string _digitSum(string s, const int k)
    {
        // 递归终止条件
        if (s.size() <= k)
        {
            return s;
        }
        // 回溯思路
        string temp = "";
        int i = 0;
        while (i < s.size())
        {
            // 得到一个子区间
            int begin = i, end = i + k; // 开区间
            // 说明当前是最后一个字符串了，直接截取到字符串末尾
            if (end >= s.size())
            {
                end = s.size(); // 开区间
            }
            int sum = 0;
            for (int j = begin; j < end; j++)
            {
                sum += (s[j] - '0');
            }
            temp += to_string(sum);
            i += k;
        }
        // 通过递归来纵向下一个字符串的遍历
        return _digitSum(temp, k);
    }

public:
    string digitSum(string s, int k)
    {
        if (s.size() == 0)
        {
            return "";
        }
        return _digitSum(s, k);
    }
};
// https://leetcode.cn/problems/calculate-digit-sum-of-a-string/