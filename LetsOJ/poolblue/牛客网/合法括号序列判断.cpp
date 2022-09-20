class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
       stack<char> b;
        for(auto ch: A)
        {
            switch(ch)
            {
                    case'('://如果是左括号，入栈
                     b.push(ch);
                     break;
                    case')'://如果是右括号，如果栈为空，返回false；不为空，将栈顶出栈
                      if(b.empty())
                      {
                      return false;
                      }
                    b.pop();
                    break;
                    default://如果是其他字符，返回false
                    return false;
            }
            
        }
        return b.empty();
      
    }
};
