//17. 电话号码的字母组合
//https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    string _numstr[10]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    //digits是主函数给予值
    //d是下标，用于遍历dig
    //cbstr是每一次的组合结果
    //retV用于最终返回
    void _combine(string digits,size_t d,string cbstr,vector<string>& retV)
    {
        if(d==digits.size())
        {   //代表这时候已经完成了匹配操作
            retV.push_back(cbstr);
            return;
        }

        size_t n = digits[d]-'0';//映射下标
        string str=_numstr[n];//找到按键对应的字母
        for(auto ch: str)
        {
            //依次对每一个字母进行+操作（下一次递归获取到的是加了之后的string）
            //这样就能保证组合完整
            _combine(digits,d+1,cbstr+ch,retV);
            //不能直接对str进行+=，因为会导致下一次的操作带有上一次的结果
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> retV;//存放最终结果
        if(digits.empty())
            return retV;

        string str;       
        _combine(digits,0,str,retV);
        return retV;
    }
};