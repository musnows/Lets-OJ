#include <vector>
#include <iostream>
using namespace std;
// https://leetcode.cn/problems/climbing-stairs/
class Solution
{
public:
    // 到了i-1后一次跳一步就能抵达i，这是方法之一
    // 到了i-2后一次跳两步就能抵达i，这是另外一个方法
    // 可得公式 dp[i] = dp[i-1] + dp[i-2]
    // 为什么到i-2后不能跳两次一步呢？因为跳一步就到i-1了，此时就不是i-2的情况了！
    // 通过公式可见这道题就是斐波那契的变种
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            int tmp = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = tmp;
        }
        return dp[2];
    }
};

// 这道题的进阶版本是一次可以爬1、2、3、...m个楼梯，问有多少种办法爬到n
// https://kamacoder.com/problempage.php?pid=1067
// 本题种这个m是2，那么我们就可以考虑怎么把这个dp推到公式扩展到m个
// 首先要知道m是2的时候，dp[i] = d[i-1] + dp[i-2]，推广到m个楼梯也是一样的，当到了i-m的时候，一次跳m个就能到达i；
// 所以最终得到的结果就是dp[i] = d[i-1] + dp[i-2] + ... + dp[i-m]
// 我们只需要新增一个for循环来进行加值就可以了。不过这一次不能使用定长的dp了，必须设置一个n+1长度的dp数组
int climbStairsM(int m, int n)
{
    vector<int> dp(n + 1, 0);
    // 本题中m可能是0，此时只有爬0楼梯的方法是固定的（即站着不动）
    dp[0] = 1;
    // 从台阶1开始遍历，需要先遍历台阶再遍历步数
    // 因为1、2和2、1是不一样的方法
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << climbStairsM(m, n) << endl;
}