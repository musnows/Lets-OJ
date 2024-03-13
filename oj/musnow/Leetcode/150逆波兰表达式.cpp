#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        map<string,function<int(int,int)>> FuncMap = {
            {"+",[](int x,int y){return x+y;}},
            {"-",[](int x,int y){return x-y;}},
            {"*",[](int x,int y){return x*y;}},
            {"/",[](int x,int y){return x/y;}}
        };
        for(auto& ch : tokens)
        {
            if(ch=="+"||ch=="-"||ch=="*"||ch=="/")
            {
                int right=s.top();
                s.pop();
                int left=s.top();
                s.pop();
                int ret = FuncMap[ch](left,right);
                s.push(ret);
            }
            else{
                s.push(stoi(ch));
            }   
        }
        return s.top();
    }
};

// https://leetcode.cn/problems/evaluate-reverse-polish-notation/

// 计算前缀表达式
int evalPN(vector<string>& tokens) {
    stack<int> s;
    map<string,function<int(int,int)>> FuncMap = {
        {"+",[](int x,int y){return x+y;}},
        {"-",[](int x,int y){return x-y;}},
        {"*",[](int x,int y){return x*y;}},
        {"/",[](int x,int y){return x/y;}}
    };
    auto riter = tokens.rbegin();
    for(;riter != tokens.rend();riter++)
    {
        string ch = *riter;
        if(ch=="+"||ch=="-"||ch=="*"||ch=="/")
        {
            int left=s.top();
            s.pop();
            int right=s.top();
            s.pop();
            int ret = FuncMap[ch](left,right);
            s.push(ret);
        }
        else{
            s.push(stoi(ch));
        }   
    }
    return s.top();
}

#include <stack>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// 后缀转中缀
string postfix_to_infix(vector<string> expr) {
    stack<string> s;
    for (int i = 0; i < expr.size(); ++i) {
        // a number
        if (!expr[i].empty() && expr[i][0] >= '0' && expr[i][0] <= '9') {
            s.push(expr[i]);
        }
        // an operator
        else {
            string second = s.top(); s.pop();
            string first = s.top(); s.pop();
            s.push("(" + first + expr[i] + second + ")");
        }
    }
    return s.top();
}

int main()
{
    vector<string> v = {"1","2","3","*","2","/","+","5","-"};
    cout << postfix_to_infix(v) << "\n";

    return 0;
}