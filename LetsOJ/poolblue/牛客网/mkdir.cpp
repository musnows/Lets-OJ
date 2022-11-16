#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int main() {
 
    int n=0;
    while(cin>>n)
    {
        
        vector<string> v(n);//提前知道空间，直接开好，避免频繁扩容
    
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        
        }
        //排序
        sort(v.begin(),v.end());
        vector<bool> flag(n,true);//伪删除法，避免删除元素，后面元素前移，效率降低
                         //提前开好，空间并都置为true，待过滤后把不符合条件的置为flase
        for(int i=0;i<n-1;i++)//n-1避免访问越界
        {   //过滤
            //处理相同目录
            if(v[i]==v[i+1])
                flag[i]=false;
            else if(v[i].size()<v[i+1].size() && v[i+1][v[i].size()]=='/'
                    && v[i]==v[i+1].substr(0,v[i].size()))//子目录
            {
                 flag[i]=false;
            }
                
        }
        for(int i=0;i<n;i++)
        {
            if(flag[i])
                cout<<"mkdir -p "<<v[i]<<endl;

        }
        cout<<endl;//多组输出用例，要输出空行
    }
    return  0;
}
