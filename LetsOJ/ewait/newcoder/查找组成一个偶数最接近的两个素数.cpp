#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
//任意一个偶数都可以由两个素数组成
//给定一个偶数，求组成z该偶数最小的两个素数的对
//示例1
//4
//输出
//2
//2
//示例2
//20
//输出
//7
//13
void CheckNums(vector<int>& v,const int& n)
{
    int i=0;
    for(i=1;i<=n;i+=2)
    {
        int sq = sqrt(i);
        int j=0;
        for(j=2;j<=sq;j++)
        {
            if(i%j==0)
            {
                break;
            }
        }
        if(j>sq)
        {
            v.push_back(i);
        }
    }
    return ;
}

int main()
{
    vector<int> v;
    vector<int> ret;
    ret.resize(2);
    int n;
    cin>>n;
    CheckNums(v, n);
    v.push_back(2);
//     for(auto& e:v){
//         cout << e<< " ";
//     }
//     cout <<endl;
    int i =0,j=0,sum=0,sub=n;
    for(i=0;i<v.size();i++)
    {
        sum=v[i];
        for(j = i;j<v.size();j++)
        {
            sum+=v[j];
            //cout << v[i] <<"-"<<v[j]<<endl;
            if((sum==n)&&((v[j]-v[i])<sub))
            {
                //cout << "good"<<endl;
                sub=v[j]-v[i];
                ret[0]=v[i];
                ret[1]=v[j];
            }
            sum=v[i];
        }
    }
    cout << ret[0]<<endl<<ret[1]<<endl;
    
    
    return 0;
}
