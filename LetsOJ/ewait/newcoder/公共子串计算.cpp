#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    string maxS = s1.size()>=s2.size()?s1:s2;
    string minS = s1.size()<s2.size()?s1:s2;
    const char*cmp =minS.c_str(),*ptr;
    int max=0;
    for(int i=0;i<maxS.size();i++)
    {
        for(int j =i+1;j<maxS.size();j++)
        {
            int len=j-i+1;
            string tmp = maxS.substr(i,len);
            const char* t1=tmp.c_str();
            ptr=strstr(cmp,t1);
            if(ptr!=NULL && max<=len)
            {
                max = len;
            }
        }
    }
    ptr=strstr(maxS.c_str(),minS.c_str());
    if(ptr!=NULL && max<=minS.size())
    {
        max = minS.size();
    }
    cout<< max<<endl;
    return 0;
}
