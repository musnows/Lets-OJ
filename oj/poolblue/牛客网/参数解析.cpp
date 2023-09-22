//https://www.nowcoder.com/practice/668603dc307e4ef4bb07bcd0615ea677?tpId=37&&tqId=21297&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void cmdLineParse(const string &str)
{   string tmp="";
    vector<string> svec;
    bool flag=false;//判断是否处于字符串状态
    for(int i=0;i<str.size();i++)
    {
                if(str[i] == '"')//判断是否是字符串的起始或结束
        {
            flag = !flag;//说明处于字符串状态
        }
        else if(str[i] == ' ' && !flag)//判断参数的分隔或者是否为字符串内容
        {
            svec.push_back(tmp);
            tmp = "";
        }
        else//正常的参数内容
        {
            tmp += str[i];
        }
     
    }   
        svec.push_back(tmp);//最后可能没有空格，需要追加
        cout<<svec.size()<<endl;
        for(auto s:svec)
        {
            cout<<s<<endl;
        }
}
int main() {
  string str;
  while (getline(cin,str)) {
    cmdLineParse(str);
  }
  return 0;
}

