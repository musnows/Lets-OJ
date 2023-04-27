// https://www.lanqiao.cn/problems/1463/learning/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
using namespace std;  
const int MAX = 1e3 + 10;// 3*10^10
typedef long long ll; 
ll arr[MAX];
int main()
{
	ll n = 2021041820210418;
	int len = 0;
	for (ll i = 1; i * i <= n; i++)// i不能等于0
	{
		if (n % i == 0)
		{
			arr[len++] = i;
			if (n / i != i)         
				arr[len++] = n / i;
		}
	}    
	ll count = 0;
	for (ll j = 0; j < len; j++)
	{
		for (ll z = 0; z < len; z++)
		{
			if (arr[j] * arr[z] > n)
				continue;
			for (ll k = 0; k < len; k++)
			{
				if (arr[j] * arr[z] * arr[k] == n)
					count++;
			}
		}
	}


	cout << count << endl;   
	return 0;
}