//字符串中找出连续最长的数字串
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str, tmp, ret;
    cin >> str;
    for(size_t i = 0; i < str.size(); ++i)
    {   //如果是数字则加上
        if(str[i] >= '0' && str[i] <= '9'){
            tmp += str[i];
        }
        else{ // 非数字时比较size大小
            if(tmp.size() > ret.size())
                ret = tmp;
            else
                tmp.clear();
        }
    }
    // i走到\0的时候，也有可能最后的数字串是最大的，
    // 但此时因为已经跳出for循环了，因此需要再比较一次
    if(tmp.size() > ret.size())
        ret = tmp;
    else
        tmp.clear();
    cout << ret << endl;
    return 0;
}
