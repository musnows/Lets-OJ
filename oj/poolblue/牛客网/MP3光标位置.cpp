#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string cmd;
    while(cin >> n >> cmd)
    {
        //将n首歌进行编号1:n，其中num代表当前光标所在的歌曲编号，first代表当前页的第一首歌编号
        int num = 1,first = 1;
        if(n <= 4)//歌曲小于4
        {
            for(int i = 0;i < cmd.size();++i)
            {
                //解析命令
                if(num == 1 && cmd[i] == 'U')
                    num = n;
                else if(num == n && cmd[i] == 'D')
                    num = 1;
                else if(cmd[i] == 'U')
                    num--;
                else
                    num++;
            }
            for(int i = 1;i <= n;++i)
            {
                cout << i << " ";
            }
            cout << endl;
            cout << num << endl;
        }
        
        else
        {
            for(int i = 0;i < cmd.size();++i)
            {
                if(first == 1 && num == 1 && cmd[i] == 'U')
                {
                    first = n - 3;//将first跳入最后一页
                    num = n;
                }
                else if(first == n - 3 && num == n && cmd[i] == 'D')
                {
                    first = num = 1;
                }
                else if(first != 1 && num == first && cmd[i] == 'U')
                {
                    first--;
                    num--;
                }
                else if(first != n-3 && num == first + 3 && cmd[i] == 'D')
                {
                    first++;
                    num++;
                }
                else if(cmd[i] == 'U')
                    num--;
                else
                    num++;
            }
            for(int i = first;i <= first+3;++i)
            {
                cout << i << " ";
            }
            cout << endl;
            cout << num << endl;
        }
    }
    return 0;
}

