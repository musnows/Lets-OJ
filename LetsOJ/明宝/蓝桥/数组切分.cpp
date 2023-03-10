#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define int long long

using namespace std;

const int N = 1e4 + 9, mod = 1e9 + 7;
int a[N];
int dp[N];
int n;

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int mi, ma;
        mi = ma = a[i];
        for (int j = i; j > 0; j--)
        {
            mi = min(mi, a[j]), ma = max(ma, a[j]);
            if (i - j == ma - mi)
            {
                dp[i] = (dp[i] + dp[j - 1])%mod;
            }
        }
    }
    cout << dp[n] % mod;
    return 0;
}