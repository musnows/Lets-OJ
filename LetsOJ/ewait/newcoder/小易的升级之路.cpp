#include<iostream>
#include<vector>
using namespace std;

//最大公约数greatest common divisor
//直接用缩写gcd
int Gcd(int a,int b)
{
    int max = a>=b?a:b;
    int min = a<b ?a:b;
    for(int i=min;i>0;i--)
    {
        if(max%i==0 && min%i==0)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int begin,num;
    vector<int> v;
    while(cin>>num>>begin)
    {
        v.resize(num);
        int k = 0;
        int end = begin;
        while(k<num && cin>>v[k])//注意这里的前后顺序，不然会吞掉下一次输入   
        {
            k++;
        }
        for(int i=0;i<num;i++)
        {
            if(v[i]<=end)
            {
                end+=v[i];
            }
            else
            {
                end+=Gcd(end,v[i]);
            }
        }
        cout<< end <<endl;
    }
    return 0;
}
//https://www.nowcoder.com/questionTerminal/fe6c73cb899c4fe1bdd773f8d3b42c3d
