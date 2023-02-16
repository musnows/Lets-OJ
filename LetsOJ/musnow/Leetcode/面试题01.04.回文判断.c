//面试题 01.04. 回文排列
//https://leetcode.cn/problems/palindrome-permutation-lcci/
//给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
//回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
//回文串不一定是字典当中的单词。
//输入："tactcoa"
//输出：true（排列有"tacocat"、"atcocta"，等等）

//思路：转换为判断字符串里面是不是每一个字符都出现了两次，或者只有一个单身狗
//开一个数组，如果数组里面没有该值，则执行插入。
bool checkin(char *s,int sz,char ch)
{
    int j;
    for(j=0;j<sz;j++)
    {
        if(ch==s[j]){
            return true;
        }
    }
    return false;
}

bool canPermutePalindrome(char* s){
    int sz1=strlen(s);
    char* str = (char*)calloc(sz1+1,sizeof(char));
    int k=0;
    int i;
    for(i=0;i<sz1;i++)
    {
        if(!checkin(str,sz1+1,s[i])){
            str[k]=s[i];
            k++;
        }
    }
    int sz2=strlen(str);
    // printf("sz1:%d  sz2:%d\n",sz1,sz2);
    // printf("str:%s\n",str);

    //情况1：整个字符串只有一个字符
    //情况2：类似于aabbccc，单数长度，但是有一个字符重复了单数次
    //      这时候计算出来的结果sz2 = 3 = (sz1/2) 符合题目要求
    //情况3：tactcoa这种情况，只有一个字符出现了单数次
    //      计算出来的sz2 = 4，sz1-sz2= 7-4 = 3 =(sz1/2)
    if(sz2==1){
        return true;
    }
    else if(sz2 == sz1/2){
        return true;
    }
    else if((sz1-sz2)!=(sz1/2)){
        return false;
    }
    
    return true;
}

void test_canPermutePalindrome()
{
    char s1[]="tactcoa";
    char s2[]="code";
    char s3[]="aaa";
    char s4[]="aabbccc";
    int ret =canPermutePalindrome(s4);
    printf("%d\n",ret);
}
