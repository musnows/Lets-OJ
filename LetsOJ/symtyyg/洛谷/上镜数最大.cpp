//https://www.luogu.com.cn/problem/CF1509A
//现有 n 个数排成一行，如果两个相邻的数 u 和 v 的平均数为整数，则认为它们是 “ 上镜 ” 的。
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;

int main()
{
	int arr[2005], t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (arr[i] % 2 == 1)
				cout << arr[i] << " ";
		}
		for (int i = 0; i < n; i++)
		{
			if (arr[i] % 2 == 0)
				cout << arr[i] << " ";
		}
	}
	return 0;
}