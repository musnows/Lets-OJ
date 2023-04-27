//HJ40 统计字符
//https://www.nowcoder.com/practice/539054b4c33b4776bc350155f7abd8f5?tpId=37&&tqId=21263&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
//输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数。
//数据范围：输入的字符串长度满足 1≤n≤1000 
#include<stdio.h>

int main()
{
    char str[1001];
    gets(str);
    int countN=0;//数字
    int countC=0;//字母
    int countS=0;//空格
    int countO=0;//其他
    
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>='0'&&str[i]<='9'){
            countN++;
        }
        else if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
            countC++;
        }
        else if(str[i]==' '){
            countS++;
        }
        else{
            countO++;
        }
    }
    printf("%d\n",countC);
    printf("%d\n",countS);
    printf("%d\n",countN);
    printf("%d\n",countO);
    
    return 0;
}
