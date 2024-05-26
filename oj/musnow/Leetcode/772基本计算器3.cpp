class Solution {
public:
// 是不是数字？
    bool isNum(char& c) { return c >= '0' && c <= '9'; }

    int calculate(string s) {
        stack<int> numSt;
        int num = 0;         // 拼数字
        char prevClac = '+'; // 上一位运算符
        // 遍历字符串，跳过空格，遇到乘除直接计算，遇到加减推后计算
        for (int i = 0; i < s.size(); i++) {
            char& c = s[i];
            if (isNum(c)) {
                num = num * 10 + int(c - '0');
            }
            // 如果是操作符（注意不能是空格），或者当前已经是最后一位了，就需要计算
            if ((!isNum(c) && c != ' ') || i == s.size() - 1) {
                // 我们把加减操作改成数字的正负来处理
                if (prevClac == '+') {
                    numSt.push(num);
                } else if (prevClac == '-') {
                    numSt.push(-num);
                }
                // 直接计算乘除，top返回的是引用
                else if (prevClac == '*') {
                    numSt.top() *= num;
                } else if (prevClac == '/') {
                    numSt.top() /= num;
                }
                // 更新操作符
                prevClac = c;
                num = 0;
            }
        }
        // 最后统一求和
        int sum = 0;
        while (!numSt.empty()) {
            sum += numSt.top();
            numSt.pop();
        }
        return sum;
    }
};