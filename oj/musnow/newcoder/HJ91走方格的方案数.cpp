#include <iostream>
using namespace std;
//https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37&&tqId=21314&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//HJ91 走方格的方案数
//请计算n*m的棋盘格子（n为横向的格子数，m为竖向的格子数）从棋盘左上角出发沿着边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。
//注：沿棋盘格之间的边缘线行走
//数据范围 1≤n,m≤8 
int main() {
    int a, b;
    cin >> a >> b;
    int sum = 1,sub=1;
    for(int i = a+b;i>b;i--){
        sum*=i;
    }
    for(int i=a;i>0;i--){
        sub*=i;
    }
    cout << sum/sub <<endl;
    return 0;
}
//这是一个数学统计题目
//排列组合
//公式https://iknow-pic.cdn.bcebos.com/9825bc315c6034a809d1be13d913495409237674
//因为只能往下和往右
//n*m就相当于n次右，m次下
//所以结果就是
//  m
// C
//  m+n
// 用数学方法算出来就可以了
