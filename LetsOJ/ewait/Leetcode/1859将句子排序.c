//1859. 将句子排序
//https://leetcode.cn/problems/sorting-the-sentence/

// 一个 句子 指的是一个序列的单词用单个空格连接起来，且开头和结尾没有任何空格。每个单词都只包含小写或大写英文字母。

// 我们可以给一个句子添加 从 1 开始的单词位置索引 ，并且将句子中所有单词 打乱顺序 。

// 比方说，句子 "This is a sentence" 可以被打乱顺序得到 "sentence4 a3 is2 This1" 或者 "is2 sentence4 This1 a3" 。
// 给你一个 打乱顺序 的句子 s ，它包含的单词不超过 9 个，请你重新构造并得到原本顺序的句子。


char * sortSentence(char * s){
    int sz=strlen(s);
    
    int end[10],begin[10];
    int b=0,e=0;
    int m=0,num=0;//下标
    for(int i=0;i<sz;i++)
    {
        if(s[i]==' ')
        {
            e=i;
            
            num=s[e-1]-'0';
            begin[num-1]=b;//利用下标映射，找到第一个单词的起始位置和结束位置
            end[num-1]=e;//空格位置
            printf("i%d num%d b%d\n",i,num,b);
            b=i+1;
            m++;
        }
        
    }
    num=s[sz-1]-'0';
    begin[num-1]=b;
    end[num-1]=sz;
    m++;
    for(int i=0;i<m;i++)
    {
        printf("p %d e %d\n",begin[i],end[i]);
    }
    char* arr=(char*)malloc((sz+1)*sizeof(sz));
    int n=0;//下标
    for(int i=0;i<m;i++)
    {
        b=begin[i];
        e=end[i];
        for(int j=b;j<e-1;j++)//e-1是为了删掉数字
        {
            arr[n++]=s[j];
        }
        arr[n++]=' ';
        // for(int h=0;h<n;h++)
        // {
        //     printf("%c",arr[h]);
        // }
    }
    arr[n-1]='\0';
    return arr;
}