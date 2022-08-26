char * makeGood(char * s){
    int i =0;
    int sz = strlen(s);
    int n = sz/2;
    while(n--)//可能一次遍历会有剩下的
    {
        for(i=0;i<sz-1;i++){
            if((s[i+1]==s[i]+32)||(s[i+1]==s[i]-32))//判断
            {
                int j=i;//移动两个
                for(j=i;j<sz-2;j++)
                {
                    s[j]=s[j+2];
                }
                s[j]='\0';//候补\0作为结尾
            }
        }
    }
    return s;
}
//1544. 整理字符串
//https://leetcode.cn/problems/make-the-string-great/
// 这道题的要求是把连续两个大小写字母，如Aa或者aA给一并删掉