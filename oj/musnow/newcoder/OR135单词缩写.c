//OR135 单词缩写
//https://www.nowcoder.com/practice/af2c953f9fc8464fa0e3252da8eb4131?tpId=182&&tqId=34861&rp=1&ru=/ta/exam-all&qru=/ta/exam-all/question-ranking
//在日常书面表达中，我们经常会碰到很长的单词，比如"localization"、"internationalization"等。为了书写方便，我们会将太长的单词进行缩写。这里进行如下定义：
//如果一个单词包含的字符个数达到或者超过10则我们认为它是一个长单词。
//所有的长单词都需要进行缩写，缩写的方法是先写下这个单词的首尾字符，然后再在首尾字符中间写上这个单词去掉首尾字符后所包含的字符个数。
//比如"localization"缩写后得到的是"l10n"，"internationalization"缩写后得到的是"i18n"。现给出n个单词，将其中的长单词进行缩写，其余的按原样输出。

char* int2str(int n)
{
    char* s=(char*)malloc(5*sizeof(char));//题目要求的中间长度不会超过4
    n-=2;//去掉头尾
    int k=0;
    while(n>0)
    {
        int tmp=n%10;
        char ch=tmp+'0';
        s[k++]=ch;
        n/=10;
    }
    s[k]='\0';
    return s;
}

void Solution()
{
        int n;
    scanf("%d",&n);
    char str[101];
    while(scanf("%s",str)!=EOF)
    {
        if(n<=0){
            break;
        }
        int sz=strlen(str);
        if(sz>=10)//长度超过10为长单词
        {
            char*mid=int2str(sz);//int转为str
            int i=0,j=1;
            //localization
            //i10n
            for(i=strlen(mid)-1;i>=0;i--)
            {
                str[j++]=mid[i];
            }
            str[j]=str[sz-1];
            str[j+1]='\0';
            printf("%s\n",str);
            free(mid);
        }
        else{
            printf("%s\n",str);
        }
        n++;
    }
}

int main()
{
    Solution();

    return 0;
}
