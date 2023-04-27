#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<long long> v;
    v.resize(100001);
    v[0]=1;
    v[1]=1;
    for(int i=2;i<v.size();i++)
    {
        long long next = v[i-1]+v[i-2];
        v[i] = next%1000000;
    }
    int n;
    while(cin>>n)
    {
        if(n>=29)
        {
            printf("%06lld\n",v[n]);  
        }
        else
        {
            printf("%lld\n",v[n]);
        }
    }
    
    return 0;
}

//https://www.nowcoder.com/questionTerminal/c0a4b917a15f40a49ca10532ab9019fb
