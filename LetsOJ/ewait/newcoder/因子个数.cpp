// write your code here cpp
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int k=0;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    n/=i;
                }
                k++;
            }
        }
        if(n!=1)
        {
            k++;
        }
        cout<<k<<endl;
    }
    
    
    return 0;
}
//这道题是看别人题解的

//从最小因子2到数字的最大因子数（数字的平方根）开始判断是否能够取余
//可以则循环取余直到取余不为0，因子个数+1；否则使用下一个因子计算；
//最终整除了各个因子数之后剩余的数字不为1则本身也是一个因子，因此因子数+1
//https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
