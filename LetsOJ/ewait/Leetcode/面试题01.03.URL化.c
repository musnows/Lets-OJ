//面试题 01.03. URL化
//https://leetcode.cn/problems/string-to-url-lcci/
//思路：直接创建一个新的字符串，根据源字符串的结果进行插入
//空间复杂度O(n),时间复杂度O(N)
//这个方法显然没原地算法好，但是好理解
char* replaceSpaces(char* S, int length) {
    char* str = (char*)malloc((length * 3 + 1) * sizeof(char));
    int i = 0, k = 0;
    S[length] = '\0';
    for (i = 0; i < length; i++)
    {
        if (S[i] != ' ') {
            str[k] = S[i];
            k++;
        }
        else {
            int j = 0;
            char* arr = "%20";
            for (j = 0; j < 3; j++)
            {
                str[k] = arr[j];
                k++;
            }
        }
    }
    str[k] = '\0';

    //自己写的for循环没有过（超时），但是strcpy过了
    //自己写一个for是因为刚开始遇到了边界控制问题，实际上只要在str的末尾加上一个\0就可以了
    // for (i = 0; i < strlen(str); i++)
    // {
    //     if (str[i] != '\0')
    //     {
    //         S[i] = str[i];
    //     }
    //     else {
    //         break;
    //     }
    // }
    // S[i] = '\0';


    strcpy(S,str);
    free(str);
    return S;
}

void test_replaceSpaces()
{
    char s[]="Mr John Smith    ";
    int sz=13;
    printf("前：%s\n",s);
    replaceSpaces(s,sz);
    printf("后：%s\n",s);
}

int main()
{
    //test04();
    test_replaceSpaces();
    return 0;
}
