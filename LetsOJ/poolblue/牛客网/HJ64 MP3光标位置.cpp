//https://www.nowcoder.com/practice/eaf5b886bd6645dd9cfb5406f3753e15?tpId=37&tqId=21287&ru=/exam/oj
//HJ64 MP3光标位置
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n=0;
  string cmd("");
  int num=1;
  while(cin>>n>>cmd)
  {   
     
          //将歌曲进行编号1-10，num代表当前歌曲编号，first是当前页数的第一首歌
      if(n<=4)//歌曲编号小于等于4
      {   
           for(int i=0;i<cmd.size();i++)
        {
          //解析命令
          if(num==1 && cmd[i]=='U')
              num=n;
          else if(num==n && cmd[i]=='D')
              num=1;
          else if(cmd[i]=='U')
            num--;
           else
              num++;
          }  
          for(int i=1;i<=n;i++)//输出
            cout<<i<<" ";//歌曲编号间隔输出空格
            cout<<endl;
            cout<<num<<endl;
        
      }
      else//歌曲编号大于四
      { int first=1;
        for(int i=0;i<cmd.size();i++) 
        {
           //解析命令
           if(num==1 && cmd[i]=='U')
           {
               first=n-3;
               num=n;
           }
           else if(first==n-3 && num==n &&cmd[i]=='D')
              first=num=1;
           else if(first!=1 && num==first &&cmd[i]=='U')
             {
                 first--;
                 num--;
             }
            else if(first!=n-3 && num==first+3 &&cmd[i]=='D')
            {
                first++;
                num++;
            }
            else if(cmd[i]=='U')
              num--;
            else 
              num++;
        }
        for(int i=first;i<=first+3;i++)//输出当前列表
          cout<<i<<" ";//歌曲编号间隔输出空格
          cout<<endl;
          cout<<num<<endl;
      }
     }     
  
  return 0; 
}

