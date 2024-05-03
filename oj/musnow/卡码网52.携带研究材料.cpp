#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, V;
    cin >> N >> V;
    vector<int> weight;
    vector<int> value;
    for (int i = 0; i < N; i++)
    {
        int w, v;
        cin >> w >> v;
        weight.push_back(w);
        value.push_back(v);
    }
    // 开始背包遍历
    vector<int> dp(V + 1, 0);
    for (int i = 0; i < weight.size(); i++)
    { // 从i物品的重量开始遍历，因为之前的放不下这个物品
        for (int j = weight[i]; j <= V; j++)
        { 
            // 遍历背包容量，从前往后遍历相当于将一个物品可以放入多次
            // 因为我们从前往后遍历，相当于会覆盖掉二维数组上一行的结果
            // 此时j之前的已经是放入过当前物品i的结果了
            // 我们继续遍历，就是保留了这个结果，相当于把i放入背包多次
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
// https://kamacoder.com/problempage.php?pid=1052