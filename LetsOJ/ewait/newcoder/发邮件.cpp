// write your code here cpp
#include<iostream>
using namespace std;

long long filb(int n)
{
    //如果是1或者0个人，放错可能性为0
    if(n<2){
        return 0;
    }//如果是两个人，只有一种情况，那就是相互拿错
    else if(n==2){
        return 1;
    }//三个人有两种拿错的情况
    else if(n==3){
        return 2;
    }
    //A的给C了
    //B拿了C的
    //A拿了B的
    
    //A发给B了
    //C拿了B的
    //A拿了C的
    
    //三个人，只有上面这两种情况
    //把A的给B或者C，是n-1种情况，随后如下：
    //1. A和B/C交换，剩下1个人，取F(N-2)的结果
    //2. 剩余2个人，可以取F(n-1)的结果
    //得到递推公式如下
    return (n-1)*(filb(n-2)+filb(n-1));
}

int main()
{
    int n;
    while(cin>>n)
    {
        cout << filb(n) << endl;
    }
    return 0;
}
//https://www.nowcoder.com/questionTerminal/95e35e7f6ad34821bc2958e37c08918b
