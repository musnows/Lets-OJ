#include<stdio.h>

//计算阶乘
double PlsN(int n)
{
    double sum = 1;
    for(int i=2;i<=n;i++)
    {
        sum*=i;
    }
    
    return sum;
}
double func(int n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    
    return (n-1)*(func(n-1)+func(n-2));
}



int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        double ret = func(n)/PlsN(n);
        printf("%2.2lf%\n",ret*100);
    }
    return 0;
}


//这是一个数学问题
//https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559
//n个人可能抽到的所有结果，是n的阶乘个
//那么每一个个人都没有抽到自己
//1.a没有拿到自己的，情况是C^1 _n-1
//2.此时b拿了a的，对于b拿到的就有两个情况
//b和a相互拿到，对于剩余的用户是一个f(n-2)的子问题
//如果b没有拿到a的，那么就是一个f(n-1)的子问题
