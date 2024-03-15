class Solution {
public:
    bool isValid(string s) {
        // 左括号入栈，右括号就将对应左括号出栈
        // 没有对应左括号就错误
        stack<char> st;
        for(auto&c:s)
        {
            if(c == '(' || c == '[' || c=='{'){
                st.push(c);
            }
            else if(c == ')'){
                if(st.empty() || st.top() != '('){
                    return false;
                }
                st.pop();
            }
            else if(c == '}'){
                if(st.empty() || st.top() != '{'){
                    return false;
                }
                st.pop();
            }
            else if(c == ']'){
                if(st.empty() || st.top() != '['){
                    return false;
                }
                st.pop();
            }
        }
        // 结束的时候如果栈还有东西就是有问题的，没有东西就是对的
        return st.empty();
    }
};

// https://leetcode.cn/problems/valid-parentheses/