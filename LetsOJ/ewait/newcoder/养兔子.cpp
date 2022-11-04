// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<long long> v;
    v.resize(91);
    v[0]=1;
    v[1]=1;
    for(int i=2;i<v.size();i++)
    {
        v[i]=v[i-1]+v[i-2];
    }
    
    int n;
    while(cin>>n)
    {
        cout<< v[n] <<endl;
    }
    
    return 0;
}
//还是一个斐波那契数列
//https://www.nowcoder.com/questionTerminal/71d3849a19f04a1591c415964ac148f1
