//给定一个字符串和其长度，返回一个布尔值判断其为合法括号串
//字符串中只含（）括号，出现其他字符为false
bool chkParenthesis(string A, int n) {
    // write code here
    stack<char> s;
    int countL = 0, countR = 0;
    for (auto c : A)
    {
        //只能由括号组成
        if (!(c == '(' || c == ')')) {
            return false;
        }
        //计数
        if (c == '(') {
            countL++;
        }
        else {
            countR++;
        }
        //入栈
        if (s.size() > 1 && c == ')')
        {
            char tmp = s.top();
            if (tmp == '(')
            {
                continue;
                //cout << countL <<"-"<<countR<<endl;   
            }
            else {
                if (countL == countR)
                {
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        else {
            s.push(c);
        }
    }

    if (countL != countR){
        return false;
    }
    return true;
}

void test_chkParenthesis()
{
    string s="(()())";
    cout << chkParenthesis(s, s.size()) << endl;
}
