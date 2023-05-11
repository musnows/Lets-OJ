#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {

    int n=0;
    while(cin>>n)
    {
        string id, op;
        set<string> s;//连接池
        size_t maxcon=0;
        for(int i=0;i<n;i++)
        {
            cin>>id>>op;//输入id和申请
          if(op=="connect")
              s.insert(id);//如果是连接，则插入
            else
              s.erase(id);//断开连接则删除id元素
            
            maxcon= max(maxcon,s.size());//计算最多插入了多少个元素
        }
       
      cout<<maxcon<<endl;          
        
    }
    return 0;
}
