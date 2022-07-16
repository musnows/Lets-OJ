//https://leetcode.cn/problems/multiply-strings/ 
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
using namespace std;
//void mulItem(string& tmp, string& num1, char a)
//{
//	int len = num1.size();
//	int flag = 0;
//	for (int i = 0; i < len; i++)
//	{
//		int ret = (num1[i] - '0') * (a - '0') + flag;
//		if (ret > 9)
//		{
//			flag = ret / 10;
//			ret %= 10;
//		}
//		else
//			flag = 0;
//
//		tmp += ret + '0';
//
//	}
//	if (flag > 0)
//		tmp += flag + '0';
//}
//
//
//int addItem(int a, int b, int& flag)
//{
//	int add = a + b + flag;
//	if (add >= 10)
//	{
//		flag = add/10;
//		add %= 10;
//	}
//	else
//		flag = 0;
//	return add;
//}
////错位相加
//void moveAdd(string& result, string& tmp, int pos)
//{
//	int i = pos;
//	int j = 0;
//	int flag = 0;
//	while (i < result.size() && j < tmp.size())
//	{
//		result[i] = addItem(result[i]-'0', tmp[j]-'0', flag)+'0';
//		++i;
//		++j;
//	}
//	// 进位
//	while (flag && i < result.size())
//	{
//		result[i] = addItem(result[i] - '0', 0, flag) + '0';
//		++i;
//	}
//	// tmp位数比result多
//	while (j < tmp.size())
//	{
//		result += addItem(0, tmp[j] - '0', flag) + '0';
//		++j;
//	}
//	if (flag)
//		result += flag + '0';
//}
//
//
//string multiply(string num1, string num2) 
//{
//	reverse(num1.begin(), num1.end());
//	reverse(num2.begin(), num2.end());
//	string tmp, result;
//	for (int i = 0;i<num2.size();i++)
//	{
//		mulItem(tmp, num1, num2[i]);
//		moveAdd(result, tmp, i);
//		tmp.clear();
//	}
//	while(result.size() != 1 && result.back() == '0')
//		result.pop_back();
//
//	//翻转数据，恢复数据
//	reverse(result.begin(), result.end());
//	return result;
//}

//}
//int main()
//{
//	string num1("51");
//	string tmp;
//	mulItem(tmp, num1, '2');
//	cout << tmp.c_str() << endl;
//	return 0;
//}
