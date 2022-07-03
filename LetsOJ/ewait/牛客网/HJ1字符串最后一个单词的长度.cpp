#include<iostream>
#include<string>
using namespace std;
//HJ1 字符串最后一个单词的长度
//https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking
int main()
{
    string s;
    getline(cin,s);
    int n1=s.rfind(' ');
    if(n1!=string::npos){//找到了空格，返回长度
        cout<<s.size()-n1-1<<endl;
    }
    else{//没有找到空格，代表只有一个单词
        cout <<s.size()<<endl;
    }
    
    return 0;
}