#include <iostream>
#include <string>
using namespace std;
void isSelf_guarding_number(int n)
{    int count=1;
    for(int i=1;i<=n;i++)
    {  
        
       long j= i*i;
        string s1=to_string(i);
        string s2=to_string(j);
        if(s2.substr(s2.length()-s1.length())==s1)
        {  
            
            count++;
        }
     }
     cout<<count<<endl;   
}    
int main(){
    int n=0;
    while(cin>>n)
    {
        isSelf_guarding_number(n);
    
    }
    return 0;
}
