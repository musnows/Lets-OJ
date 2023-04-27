//https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
//17. 电话号码的字母组合
class Solution {
    //建立电话数字按键和字符串的映射
    string  _numToStr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:                        
    void _letterCombine(string digits,size_t di ,string combineStr,vector<string>& retV)
    {  
        if(di==digits.size())//n层遍历结束，将当前组合放进数组并返回上一层
        {
            retV.push_back(combineStr);
            return;
        }
       //把数字字符串转换为数字
       int num= digits[di]-'0';//"234"-"2"-"3"-"4"
       string str= _numToStr[num];//'abc'
       for(auto ch:str)
      {                                 //下一层不影响上一层
             _letterCombine(digits,di+1,combineStr+ch,retV);//一层一层递归，分别组合，返回上一层
      }
    }                                
    vector<string> letterCombinations(string digits) {
      vector <string> retV;
      //当是空字符串时
      if(digits.empty())
        return retV;
      size_t di=0;
      string str;
      _letterCombine(digits,di,str,retV);//进行递归组合
      return retV;
    }
};
