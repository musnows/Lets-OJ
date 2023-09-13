//https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false 
#include <iostream>
#include <algorithm>    // std::sort
#include <vector>  
using namespace std;

int main() {
    //输入
    int n;
    cin>>n;
    vector<int> All_team(3*n);
    for(int i=0;i<3*n;i++)
    {
        cin>>All_team[i];
    }

    sort(All_team.begin(),All_team.end());//排序
    
    long long sum=0;//longlong避免数值太大放不下
    for(int i=0;i<n;i++)
    {
        sum+=All_team[All_team.size()-2*(i+1)];
    }
    cout<<sum<<endl;

    return 0;
}

