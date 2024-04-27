class Solution {
    // 我们需要按顺序从高到低遍历
    const vector<pair<int, string>> maps = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"},
    };

public:
    string intToRoman(int num) {
        string str("");
        int cur = num;
        // C++17的结构化绑定
        for (auto& [i, s] : maps) {
            // 看看包含几个这样的值
            while (cur >= i) {
                str += s;
                cur -= i;
            }
            // 没有值了就退出
            if (cur == 0) {
                break;
            }
        }
        return str;
    }
};