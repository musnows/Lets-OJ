//面试题 01.06. 字符串压缩
//https://leetcode.cn/problems/compress-string-lcci/
//字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。
char* int2str(int n){
    char* s=(char*)malloc(6*sizeof(char));//题目要求的字符长度不会超过5
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


char* compressString(char* S){
    int sz1=strlen(S);
    if(sz1<=2)
    {
        return S;
    }
    char* arr=(char*)malloc((sz1*2)*sizeof(char));
    int i=0,count=0;
    int k=0;//arr下标
    char ch=S[i];
    for(i=0;i<sz1;i++)
    {
        //如果这个字符只有一个，直接得出count
        if(S[i]==ch&&S[i+1]!=ch){
            count=1;
        }
        else
        {//字符有很多，开始计数
            while(S[i]==ch)
            {
                count++;
                i++;
            }
            i--;//这里i--是因为循环结束的时候for循环会让i++一次
        }
        arr[k++]=ch;
        if(count<=9){
            arr[k++]=count+'0';
        }
        else{
            //大于9的数需要特殊转换
            char*ret=int2str(count);
            int j=0;
            for(j=strlen(ret)-1;j>=0;j--){
                arr[k++]=ret[j];
            }
            free(ret);
        }
        
        count=0;//重置count
        //避免出现越界访问
        if(i<sz1-1){
            ch=S[i+1];
        }
    }
    arr[k]='\0';

    int sz2=strlen(arr);
    if(sz2<=sz1){
        strcpy(S,arr);
    }
    free(arr);
    return S;
}

void test_compressString()
{
    //预期结果"r5L5P6R5g3N5V10D10I10l7A4q7b3N4f6"
    char str[]="rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff";
    char*ret=compressString(str);
    printf("%s\n",ret);
}
