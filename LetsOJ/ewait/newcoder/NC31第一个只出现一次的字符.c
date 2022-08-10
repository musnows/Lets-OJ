//NC31 第一个只出现一次的字符
//https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=188&&tqId=38575&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
//在一个长为 字符串中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
int FirstNotRepeatingChar(char* str) {
    char* fast=str;
    char* slow=str;
    int sz=strlen(str);
    int flag=0;//标识为
    int i=0;
    for(i=0;i<sz;i++)
    {
        slow=str+i;
        fast=str;//直接从头开始遍历
        flag=0;//标识位需要重置
        while(fast<=str+sz)
        {
            if(fast==slow){//遇到slow的时候跳过
                fast++;
            }
            else if(*slow != *fast){//值不同的时候跳过
                fast++;
            }
            else{//值相同，修改标记位
                flag=1;
                break;
            }
        }
        if(flag!=1){
            return slow-str;
        }
    }

    return -1;
}

int main()
{
    //test03();
    char* arr="google";
    int ret = FirstNotRepeatingChar(arr);
    printf("ret=%d\n",ret);
    return 0; 
}
