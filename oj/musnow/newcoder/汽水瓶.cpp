#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0){
            return 0;
        }
        
        int sum = 0,left=n;
        while(left>2)
        {
            sum+=left/3;//可以换几瓶汽水
            left = left/3+left%3;//剩下几个空瓶子
        }
        //只有剩下两个瓶子的情况，才可以找老板要一个
        if(left==2){
            sum++;
        }
        
        cout << sum << endl;
    }
    return 0;
}

//三个汽水瓶可以换一个汽水，空瓶子不够可以找老板要，但是必须归还
//n是已有空瓶子个数
//多组输入，范文1到100，输入0代表结束
