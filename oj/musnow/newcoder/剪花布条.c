// write your code here cpp
#include<string.h>
#include<stdio.h>

int main()
{
    char s1[1001],s2[1001];
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        //printf("%s %s\n",s1,s2);
        int count =0;
        int sz2 = strlen(s2);
        char*ret = strstr(s1,s2);
        while(ret!=NULL)
        {
            count++;
            int diff = ret-s1;
            ret = strstr(s1+diff+sz2,s2);
        }
        printf("%d\n",count);
    }
    
    return 0;
}
//题目要求很简单，就是在字符s1里面找有几个s2
//
