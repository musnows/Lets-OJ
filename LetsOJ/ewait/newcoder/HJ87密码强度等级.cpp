//https://www.nowcoder.com/questionTerminal/52d382c2a7164767bca2064c1c9d5361
//密码强度等级

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
//计算符号个数
static int countSign = 0;
static const char* signStr = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
void IsSign(const char& c)
{
    int sz = strlen(signStr);
    for(int i =0;i<sz;i++)
    {
        //cout << signStr[i];
        if(c == signStr[i])
        {
            countSign++;
            return;
        }
    }
    //cout << endl;
}

//判断密码长度
void CheckLengths(const string&s,int& sum)
{
    if(s.size()<=0){
        return ;
    }
    //加分，依据长度
    if(s.size()<=4){
        sum+=5;
    }
    else if(s.size()<=7){
        sum+=10;
    }
    else{
        sum+=25;
    }
    return ;
}
//检查字母和数字,返回一个bool数组
//第一位代表小写，第二位代表大写，第三位代表数字
vector<bool> CheckWordsNums(const string &s, int &sum)
{
    vector<bool> ret = {true,true,true};
    int counta=0,countA=0,countNum=0;
    for(auto e:s)
    {
        if(e>='a'&&e<='z'){
            counta++;//计数小写字母
        }
        else if(e>='A'&&e<='Z'){
            countA++;//计数大写字母
        }
        else if(e>='0'&&e<='9')
        {
            countNum++;
        }
        else{
            IsSign(e);//符号判断
        }
    }
    //进行判断，注意规则
    if(countA > 0 && counta >0)
    { //1.大小写混合，20分
       sum+=20;
    }
    else if(countA>0&&counta==0)
    {// 只有大写
        sum+=10;
        ret[0]=false;
    }
    else if(counta>0&&countA==0)
    {// 只有小写
        sum+=10;
        ret[1]=false;
    }
    else{//3.没有字母
        ret[0]=false;
        ret[1]=false;
    }
    //判断是数字，给分
    if(countNum>1)
    {
        sum+=20;  
    }
    else if(countNum==1)
    {
        sum+=10;
    }
    else{//没有数字
        ret[2]=false;
    }    
    return ret; 
}
//判断一共有几个符号
bool CheckSign(const string&s,int& sum)
{
    //cout<<"countSign: "<<countSign<<endl;
    if(countSign>1){
        sum+=25;
    }
    else if(countSign==1){
        sum+=10;
    }
    else{//没有符号
        return false;
    }
    return true;
}
//打印最终结果
void FinalPrint(const int&sum)
{
    if(sum>=90)
    {
        cout << "VERY_SECURE" <<endl;
    }
    else if(sum>=80)
    {
        cout<<"SECURE"<<endl;
    }
    else if(sum>=70)
    {
        cout<<"VERY_STRONG"<<endl;
    }
    else if(sum>=60)
    {
        cout<<"STRONG"<<endl;
    }
    else if(sum>=50)
    {
        cout<<"AVERAGE"<<endl;
    }
    else if(sum>=25)
    {
        cout<<"WEAK"<<endl;
    }
    else if(sum>=0)
    {
        cout<<"VERY_WEAK"<<endl;
    }
}

void TestPasswd()
{
    string s;
    cin >> s;
    int sum = 0;
    CheckLengths(s,sum);
    //cout << "CheckLengths: "<<sum<<endl;
    vector<bool> ifWN = CheckWordsNums(s, sum);
    //cout << "CheckWordsNums: "<< sum <<endl;
//     for(auto e:ifWN){
//         cout << e << " ";
//     }
//     cout << endl;
    bool ifSign = CheckSign(s, sum);
    //cout << "CheckSign: "<< sum << " ifSign: " << ifSign << endl;
    
    //最后再上奖励分
    //1.大小写字母、数字、符号都有
    if((ifWN[0] && ifWN[1]) && ifWN[2] && ifSign)
    {
        sum+=5;
    }
    else if((ifWN[0]||ifWN[1]) && ifWN[2])//只有大(小)写字母和数字
    {
        sum+=2;
    }
    else if((ifWN[0]||ifWN[1]) && ifWN[2] && ifSign)//只有大(小)写字母、数字、符号
    {
        sum+=3;
    }
    //cout << "finial: " << sum << endl;
    FinalPrint(sum);//最终结果打印
}

int main()
{
    TestPasswd();
    return 0;
}
