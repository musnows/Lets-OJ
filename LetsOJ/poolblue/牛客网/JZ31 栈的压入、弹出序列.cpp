#define _CRT_SECURE_NO_WARNINGS
//https ://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//JZ31 栈的压入、弹出序列
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {

        stack<int> st;
        int j = 0;
        for (auto e : pushV)//循环结束，入栈序列结束
        {
            //入栈
            st.push(e);
            while (!st.empty() && st.top() == popV[j])
            {
                //出栈
                j++;
                st.pop();

            }
        }
        return st.empty();//无元素说明匹配上，有则匹配错误

    }

};