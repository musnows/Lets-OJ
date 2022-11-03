// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<long long> v;
    v.resize(81);
    v[0]=1;
    v[1]=1;
    for(int i=2;i<v.size();i++)
    {
        v[i]=v[i-1]+v[i-2];
    }
    int f,t;
    while(cin>>f>>t)
    {
        long long ret = 0;
        for(long long i=f;i<=t;i++)
        {
            ret+=v[i-1];
        }
        cout<<ret<<endl;
    }
    
    return 0;
}
//https://www.nowcoder.com/questionTerminal/3549ff22ae2c4da4890e9ad0ccb6150d
