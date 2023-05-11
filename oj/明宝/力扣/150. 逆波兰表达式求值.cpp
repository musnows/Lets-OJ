//https://leetcode.cn/problems/evaluate-reverse-polish-notation/
#define _CRT_SECURE_NO_WARNINGS 
// 用包装器和lambda表达式简化代码
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<long long> s;
		map<string, function<long long(long long, long long)>> opFuncMap = {
			{"+", [](long long x, long long y) {return x + y; }},
			{"-", [](long long x, long long y) {return x - y; }},
			{"*", [](long long x, long long y) {return x * y; }},
			{"/", [](long long x, long long y) {return x / y; }}
		};

		for (auto& str : tokens)
		{
			if (opFuncMap.count(str))
			{
				long long right = s.top();
				s.pop();
				long long left = s.top();
				s.pop();

				s.push(opFuncMap[str](left, right));// operate[]调用对应的lambda表达式
			}
			else
			{
				s.push(stoll(str));
			}
		}
		return s.top();
	}
};

// 普通写法
//class Solution {
//public:
//	int strToInt(string& str)// 用stoi代替
//	{
//		int sum = 0;
//		for (auto i : str)
//		{
//			sum = sum * 10 + (i - '0');
//		}
//		return sum;
//	}
//	int evalRPN(vector<string>& tokens) {
//		stack<int> st;
//		for (const auto& str : tokens)
//		{
//			if (!st.empty() && (str == "+" || str == "-" || str == "*" || str == "/"))
//			{
//				int i = st.top();
//				st.pop();
//				// if(!st.empty())// 没必要，操作数是算好的
//				// {
//				int j = st.top();
//				st.pop();
//				int ret;
//				if (str == "+")
//					ret = j + i;
//				if (str == "-")
//					ret = j - i;
//				if (str == "*")
//					ret = j * i;
//				if (str == "/")
//					ret = j / i;
//
//				st.push(ret);
//				//}
//				// else
//				//     return i;
//			}
//			else
//			{
//				st.push(stoi(str));
//			}
//		}
//		return st.top();
//	}
//};