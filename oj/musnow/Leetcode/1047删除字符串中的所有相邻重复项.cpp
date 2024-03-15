class Solution {
public:
    string removeDuplicates(string s) {
        // 字符入栈
        stack<char> st;
        for(auto& c:s){
            // 栈内没有元素，或者栈顶元素和当前不同
            if(st.empty() || st.top() != c){
                st.push(c);
            }
            else
            {
                // 如果栈顶和当前字符相同，则出栈到栈顶和当前字符不同
                while(!st.empty() && st.top() == c)
                {
                    st.pop();
                }
            }

        }
        // 结束了之后，栈内元素就是结果
        // 注意栈只能从栈顶出，所以出栈顺序是反的
        string retStr;
        while(!st.empty())
        {
            retStr += st.top();
            st.pop();
        }
        reverse(retStr.begin(),retStr.end());
        return retStr;
    }
};