// https://kamacoder.com/problempage.php?pid=1066
#include <bits/stdc++.h>
using namespace std;

// 多重背包在01背包的基础上，多了每个物品的数量
// 那么我们可以把每个物品数量拆分，即把乘法改成加法
// 比如 2 个 a 物品，可以变成列表中有 2 个重量和价值都与 a 相同的物品
// 物品重量 价值 数量
//    10    10   2
//      等价于
//    10    10   1
//    10    10   1
// 这样拆分了之后，每一个物品其实只有一个了，就等价于一个01背包。
int main()
{
    // c是背包重量，n是矿石种类
    int c, n;
    cin >> c >> n;
    vector<int> weight(n), price(n), num(n);
    for (int i = 0; i < weight.size(); i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < price.size(); i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < num.size(); i++)
    {
        cin >> num[i];
    }
    // 在01背包的遍历中，加一层对物品数量的遍历就可以了
    vector<int> dp(c + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < num[i]; k++)
        {
            // 必须从后往前遍历，一个物品只用一次
            for (int j = c; j >= weight[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - weight[i]] + price[i]);
            }
        }
    }
    cout << dp[c] << endl;
    return 0;
}