//面试题 01.02. 判定是否互为字符重排
//https://leetcode.cn/problems/check-permutation-lcci/
//给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
//输入: s1 = "abc", s2 = "bca"
//输出: true 
void swap(char *a,char *b)
{
    char tmp=*a;
    *a=*b;
    *b=tmp;
}
//思路：
//两次for遍历，在s2里面找到和s1相同字符的时候，交换道s1该字符的对应位置
//如果遍历完之后，s1和s2相等，代表可以改成相同的字符串，符合题目要求，返回真
//如果遍历完之后，s1和s2不相等，那么说明s2里面缺少了s1内包含的字符，返回假

bool CheckPermutation(char* s1, char* s2){
    //为了避免源被修改，这里开一个相同长度的，然后拷贝一份
    char str[101]={0};
    strcpy(str,s2);
    //因为sz是一样的，所以只需要计算一个
    char sz=strlen(s1);
    for(int i =0;i<sz-1;i++)
    {
        for(int j = i; j<sz; j++)
        {
            if(s1[i]==str[j] && i!=j){
                swap(&str[i],&str[j]);
                break;
            }
            else if(s1[i]==str[j] && i==j)
            {
                break;
            }
        }
    }
    //printf("s1: %s s2: %s\n",s1,str);
    return !strcmp(s1,str);
}

void test_CheckPermutation()
{
    char s1[101];
    char s2[101];
    scanf("%s",&s1);
    scanf("%s",&s2);
    printf("s1: %s s2: %s\n",s1,s2);
    int ret=CheckPermutation(s1,s2);
    printf("%d\n",ret);
    printf("s1: %s s2: %s\n",s1,s2);

}
