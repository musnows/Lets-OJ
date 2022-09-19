#include<iostream>
#include<string>
using namespace std;

//给定一个256字符的字符串，输出内部最长数字子串
bool isNumStr(const char& c)
{
    return (c>='0' && c<='9') ;
}

int main()
{
    string s;//来源
    string ret_s;//结果
    getline(cin,s);
    
    int begin=0;//标记数字串的开始
    int count=0;//标记长度
    int max = 0,mbegin;//上一次获取到的数据串长度和起始位置
    int flag = 0;//标记位
    for(int i=0;i<s.size();i++)
    {
        if(i<s.size()-1 && isNumStr(s[i]) && isNumStr(s[i+1]))
        {       
            count++;
            if(flag!=1){
                begin=i;//说明开始计算了
                flag=1;
            }
            //cout<<"i"<<i<<" c"<<count<<" b"<<begin<<endl;
        }
        else if(isNumStr(s[i]))//自己还是数字，但是下一位不是
        {
            count++;
            //cout<<"i"<<i<<" c"<<count<<" b"<<begin<<endl;
        }
        else{
            if(count>=max){
                max=count;//最大的长度
                mbegin=begin;//最大长度的起始位置
            }
            count=0;//置零
            flag=0;
        }

    }
    if(count>=max)
    {//循环结束后还需要一次判断，避免最后一个字符依旧是数字的情况
        max=count;
        mbegin=begin;
    }
    
    
    //cout<<"max"<<max<<" mbegin"<<begin<<endl;
    int n = mbegin;//下标
    ret_s.resize(max+1);
    for(int j =0;j<max;j++)
    {
        ret_s[j]=s[n++];
    }
    //s[n]='\0';//string不需要进行末尾处理
    cout<<ret_s<<"#";
    
    return 0;
}