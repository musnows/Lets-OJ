class Solution {
    vector<string> num2str = {
        "", /* 0 */
        "", /* 1 */
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };


    void _letterCombinations(const string& digits,int index,string str,vector<string>& retV) {
        if(index >= digits.size()){
            retV.push_back(str);
            return;
        }
        // 通过ascii的计算得出当前数字，并找到curStr中映射的字符串
        int num = digits[index] - '0';
        if(num < 2) // 没有对应的
        {
            retV.push_back(str);
            return;
        }
        // 一层的遍历
        string& curStr = num2str[num];
        for(int i = 0;i<curStr.size();i++){
            str.push_back(curStr[i]);
            _letterCombinations(digits,index+1,str,retV);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> retV;
        // 单独判断一下空字符串
        if(digits == ""){
            return retV;
        }

        _letterCombinations(digits,0,"",retV);
        return retV;
    }
};

// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/