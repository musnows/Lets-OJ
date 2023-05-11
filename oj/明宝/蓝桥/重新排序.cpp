//https://www.lanqiao.cn/problems/2128/learning
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 10;// 要这样写啊
typedef long long ll;
int arr[MAX], s[MAX];
ll sum1, sum2;
int main()
{
    int n = 0, m = 0, l = 0, r = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;

    // 可以算出重复区域，和它的权重
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        s[l]++;
        s[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        s[i] += s[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        sum1 += (ll)arr[i] * s[i];// 记得强转
    }
    // 计算最大可能性
    sort(arr + 1, arr + n + 1);
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum2 += (ll)arr[i] * s[i];
    }
    cout << sum2 - sum1 << endl;
    return 0;
}