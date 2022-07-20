//https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking
//HJ1 字符串最后一个单词的长度
#include <iostream>
using namespace std;
int main()
{   
    string str ;
    getline(cin,str); //若单纯用cin>> str; 只能读取一段字符，空格间隔后的字符读不到
    size_t pos=str.rfind(' ');
    if(pos != string::npos)
    {
        cout<< str.size()-pos-1 <<endl;
    }
    else
    {
        cout<<str.size()<<endl;
     }
    return 0;
}