// https://kamacoder.com/problempage.php?pid=1046

// 小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。他需要带一些研究材料，但是他的行李箱空间有限。
// 这些研究材料包括实验设备、文献资料和实验样本等等，它们各自占据不同的空间，并且具有不同的价值。
// 小明的行李空间为 N，问小明应该如何抉择，才能携带最大价值的研究材料，每种研究材料只能选择一次，并且只有选与不选两种选择，不能进行切割。

// 第一行包含两个正整数，第一个整数 M 代表研究材料的种类，第二个正整数 N，代表小明的行李空间。
// 第二行包含 M 个正整数，代表每种研究材料的所占空间。
// 第三行包含 M 个正整数，代表每种研究材料的价值。

// 输入示例
// 6 1
// 2 2 3 1 5 2
// 2 3 1 5 4 3
// 输出示例
// 5
// 提示信息
// 小明能够携带 6 种研究材料，但是行李空间只有 1，而占用空间为 1 的研究材料价值为 5，所以最终答案输出 5。

// 数据范围：
// 1 <= N <= 5000
// 1 <= M <= 5000
// 研究材料占用空间和价值都小于等于 1000

#include <bits/stdc++.h>
using namespace std;

// m是物品种类，n是背包重量，需要一个m*(n+1)的矩阵
int packageFunc(int m, int n, vector<int> &space, vector<int> &value)
{
    // 没有物品，直接退出
    if (space.size() == 0)
    {
        return 0;
    }
    // 每一行代表某一个物品，每一列代表当前背包中物品重量
    vector<vector<int>> mtx(m, vector<int>(n + 1, 0)); // 矩阵
    // 1.首先第一列都是0，因为此时背包中物品重量都是0，但因为我们本来就初始化了全0，所以不用单独处理第一列
    // 2.第一行是携带第一个物品后，背包的价值。只要背包重量大于这个物品重量的位置，都需要设置为该物品的价格
    for (int j = space[0]; j < mtx[0].size(); j++)
    {
        mtx[0][j] = value[0];
    }
    // 3.开始扩展遍历，分为两种情况
    //      情况1：不带当前行的物品，此时当前背包的价值是上一行同列的价值
    //      情况2：带当前的物品。此时背包价值是 上一行减去当前物品重量后背包剩余价值 + 当前物品价值
    //      我们需要选择这两个情况的最大值。
    int maxValue = -1;
    for (int i = 1; i < mtx.size(); i++)
    {
        // 第一列都是0，不需要遍历
        for (int j = 1; j < mtx[i].size(); j++)
        {
            int value1 = mtx[i - 1][j]; // 不带当前物品
            // 现在背包已有重量带不下当前物品
            if (j < space[i])
            {
                mtx[i][j] = value1;
                continue;
            }
            int value2 = mtx[i - 1][j - space[i]] + value[i]; // 带当前物品
            mtx[i][j] = max(value1, value2);
            maxValue = max(maxValue, mtx[i][j]);
        }
    }
    // 如果maxValue为-1，代表循环没有更新出最大值来，这说明space和value只有一个
    // 判断space是否大于背包重量，如果不大于，则直接返回value[0]，否则返回0
    if (maxValue == -1)
    {
        return space[0] > n ? 0 : value[0];
    }
    return maxValue;
}

// m是物品种类，n是背包重量，需要一个m*(n+1)的矩阵
// 改成一维数组
int packageFunc2(int m, int n, vector<int> &space, vector<int> &value)
{
    // 没有物品，直接退出
    if (space.size() == 0)
    {
        return 0;
    }
    // 每一行代表某一个物品，每一列代表当前背包中物品重量
    vector<int> mtx(n + 1, 0);
    // 1.首先第一列都是0，因为此时背包中物品重量都是0，但因为我们本来就初始化了全0，所以不用单独处理第一列
    // 2.第一行是携带第一个物品后，背包的价值。只要背包重量大于这个物品重量的位置，都需要设置为该物品的价格
    for (int j = space[0]; j < mtx.size(); j++){
        mtx[j] = value[0];
    }
    // 3.开始扩展遍历，分为两种情况
    //      情况1：不带当前行的物品，此时当前背包的价值是上一行同列的价值
    //      情况2：带当前的物品。此时背包价值是 上一行减去当前物品重量后背包剩余价值 + 当前物品价值
    //      我们需要选择这两个情况的最大值。
    int maxValue = -1;
    // 在二维数组中，我们是获取到上一行的结果，但实际上我们当前行会保留一部分上一行的结果，递推公式可以直接写出来
    // 从第二个商品开始处理
    for(int i = 1;i<m;i++){
        // 第一列永远是0
        // 这里必须从后往前遍历，因为我们现在只有一行数组了
        // 如果从前往后遍历，那么后续获取到的就不一定是上一行的值了
        // 此时就相当于当前物品i被放入了多次，不符合题目要求
        for(int j = mtx.size()-1;j>=1;j--){
            if(j < space[i]){
                // 本来这里是等于dp[i-1][j]的
                // 但是我们直接不做任何操作，相当于保留了上一行的结果
                continue;
            }
            int value1 = mtx[j]; // 不添加当前物品（上一行的值）
            int value2 = mtx[j-space[i]] + value[i]; // 添加当前物品
            mtx[j] = max(value1,value2);
            maxValue = max(maxValue,mtx[j]);
        }
    }
    // 如果maxValue为-1，代表循环没有更新出最大值来，这说明space和value只有一个
    // 判断space是否大于背包重量，如果不大于，则直接返回value[0]，否则返回0
    if (maxValue == -1)
    {
        return space[0] > n ? 0 : value[0];
    }
    return maxValue;
}

int main()
{
    // int m =6;
    // int n = 1;
    // vector<int> space = {2,2,3,1,5,2};
    // vector<int> value = {2,3,1,5,4,3};
    int m, n;
    while (cin >> m >> n)
    {
        vector<int> space(m);
        vector<int> value(m);
        for (int i = 0; i < m; i++)
        {
            cin >> space[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> value[i];
        }
        cout << packageFunc2(m, n, space, value) << endl;
    }
    return 0;
}