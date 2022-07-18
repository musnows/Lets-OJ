//https://leetcode.cn/problems/evaluate-reverse-polish-notation/submissions/
//150逆波兰表达式
//笔记https://blog.csdn.net/muxuen/article/details/125846430?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22125846430%22%2C%22source%22%3A%22muxuen%22%7D&ctrtid=bUwV6
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto& ch : tokens)
        {
            if(ch=="+"||ch=="-"||ch=="*"||ch=="/")
            {
                int right=s.top();
                s.pop();
                int left=s.top();
                s.pop();
                switch(ch[0])
                {
                    case '+':
                        s.push(left+right);
                        break;
                    case '-':
                        s.push(left-right);
                        break;
                    case '*':
                        s.push(left*right);
                        break;
                    case '/':
                        s.push(left/right);
                        break;
                    default:
                        break;
                }
            }
            else{
                s.push(stoi(ch));
            }   
        }
        return s.top();
    }
};