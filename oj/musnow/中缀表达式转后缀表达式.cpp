#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// 判断当前的操作符优先级是不是比栈顶更高？
bool isCalcHigher(const string &cur, const string &target)
{
    // 如果是乘除，且栈顶是加减，那么优先级就更高
    if ((cur == "*" || cur == "/") && (target == "+" || target == "-"))
    {
        return true;
    }
    // 如果target是左括号，则为true
    if (target == "(")
    {
        return true;
    }
    // 其他情况，包括栈顶也是乘除的情况，优先级都低
    return false;
}

// 修改中缀表达式为合法表达式
void stringHandler(string &s)
{
    // 去除所有空格
    std::string tmp;
    for (auto &c : s)
    {
        if (c != ' ')
        {
            tmp += c;
        }
    }
    // 处理独立的负号
    // (-n) -> (0-n)
    // (+n) -> (0+n)
    // 开头的-n -> 0-n
    // 开头的+n -> 0+n
    s.resize(0);
    int n = tmp.length();
    for (int i = 0; i < n; ++i)
    {
        // 开头的-n或者括号里面的-n
        if (tmp[i] == '-' && (i == 0 || tmp[i - 1] == '('))
        {
            s += "0-";
        }
        // 开头的+n或者括号里面的+n
        else if (tmp[i] == '+' && (i == 0 || tmp[i - 1] == '('))
        {
            s += "0+";
        }
        else
        {
            // 其他情况说明是有匹配的表达式的，所以不需要处理
            s += tmp[i];
        }
    }
}

// 中序表达式转后缀表达式
vector<string> inOrderTobackOrder(string &s)
{
    vector<string> retV;
    stack<string> st; //  操作符栈
    string num;       // 零时存放数字
    // 重新处理string，让其变成完整的中序表达式
    stringHandler(s);
    cout << "handle: " << s << endl;
    // 开始遍历
    for (auto &itr : s)
    {
        string c;
        c.push_back(itr);
        // 跳过空格
        if (c == " ")
        {
            continue;
        }
        // 操作数
        if (c >= "0" && c <= "9")
        {
            num.push_back(c[0]);
            continue;
        }
        // 其他情况都说明不是操作数，需要将之前的操作数输出
        if (num.size() > 0)
        {
            retV.push_back(num);
            num.resize(0);
        }

        // 左括号入栈
        if (c == "(")
        {
            st.push(c);
        }
        // 遇到右括号，需要一直出栈内操作符，直到遇到左括号
        else if (c == ")")
        {
            // 遇到右括号的时候不可能出现栈为空的情况
            while (st.top() != "(")
            {
                retV.emplace_back(st.top());
                st.pop();
            }
            st.pop(); // 弹出左括号
        }
        // 如果栈为空，则入栈
        else if (st.empty())
        {
            st.push(c);
        }
        else // 其他操作符
        {
            // 栈不为空，和栈顶的优先级进行比较
            // 操作符优先级高于栈顶，入栈;
            if (isCalcHigher(c, st.top()))
            {
                st.push(c);
                continue;
            }
            // 优先级低于/等于栈顶操作符，将栈顶出栈（放入结果表达式）
            retV.emplace_back(st.top());
            st.pop();
            // 继续判断，直到高于栈顶运算符
            while (!st.empty() && !isCalcHigher(c, st.top()))
            {
                retV.emplace_back(st.top());
                st.pop();
            }
            // 栈顶高于当前运算符或栈为空，入栈
            st.push(c);
        }
    }
    // num不为空，还需要处理
    if (num.size() > 0)
    {
        retV.push_back(num);
    }
    // 结束遍历，将栈内操作符依次输出，即得到了最终的后缀表达式
    while (!st.empty())
    {
        retV.emplace_back(st.top());
        st.pop();
    }
    return retV;
}

int main()
{
    string s;
    cout << "enter inOrder > ";
    getline(cin, s);
    // 处理
    auto retV = inOrderTobackOrder(s);
    cout << "backOrder result: [";
    for (int i = 0; i < retV.size(); i++)
    {
        cout << "\"" << retV[i] << "\"";
        if (i != retV.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}