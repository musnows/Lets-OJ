//https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&ru=/exam/oj
class Solution {
public:
    //动态规划
    int jumpFloorII(int number) {
        vector<int>dp(number + 1);
        //因为0级台阶和1级台阶只有一个方案，初始化前俩个
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= number; i++)
        {
            dp[i] = 2 * dp[i - 1];

        }
        return dp[number];
    }
};
//方法二：递归（扩展思路）
// 思路：
// 根据上述思路，我们还可以从后往前，因为f(n)=2∗f(n−1)f(n)=2*f(n-1)f(n)=2∗f(n−1)，相当于找到子问题，其答案的两倍就是父问题的答案。
// class Solution {
// public:
//     int jumpFloorII(int number) {
//         //1或0都是1种
//         if(number <= 1) 
//             return 1;
//         //f(n) = 2*f(n-1)
//         return 2 * jumpFloorII(number - 1); 
//     }
// };

//我们也可以发现从第一个数1开始，后面每个数都是在前一个数的基础上乘2，而最开始的数字为1，所以f(n)=2n−1f(n)=2^{n-1}f(n)=2^n−1
// class Solution {
// public:
//     int jumpFloorII(int number) {
//         if(number <= 1)
//             return 1;
//         //直接次方
//         return pow(2, number - 1); 
//     }
// };
