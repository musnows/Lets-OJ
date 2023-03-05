#define _CRT_SECURE_NO_WARNINGS

// 当两个数各个数位之和不同时, 将数位和较小的排在前面, 当数位之和相等时, 将数值小的排在前面。
//例如, 2022 排在 409 前面, 因为 2022 的数位之和是 6, 小于 409 的数位 之和 13 。
//又如, 6 排在 2022 前面, 因为它们的数位之和相同, 而 6 小于 2022 。
//给定正整数n, m, 请问对 1 到n 采用这种方法排序时, 排在第m 个的元 素是多少 ?

// sort+lambda重写
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int fun(int n)
{
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	sort(v.begin(), v.end(), [](int a, int b) {return (fun(a) < fun(b)) || (fun(a) == fun(b) && a<b); });
	cout << v[m - 1] << endl;

	return 0;
}
