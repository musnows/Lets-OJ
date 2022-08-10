//leetcode 面试题 01.01. 判定字符是否唯一
//https://leetcode.cn/problems/is-unique-lcci/
bool isUnique(char* astr){
    char* fast=astr;
    char* slow=astr;
    int sz=strlen(astr);
    int flag=0;//标识为
    int i=0;
    for(i=0;i<sz;i++)
    {
        slow=astr+i;
        fast=astr;//直接从头开始遍历
        flag=0;//标识位需要重置
        while(fast<=astr+sz)
        {
            if(fast==slow){//遇到slow的时候跳过
                fast++;
            }
            else if(*slow != *fast){//值不同的时候跳过
                fast++;
            }
            else{//值相同，直接返回假
                return false;
            }
        }
    }
    //全部遍历完，代表没有相同的字符，返回真
    return true;
}

int main()
{
    //test03();
    char* arr="go1le";
    // int ret = FirstNotRepeatingChar(arr);
    bool ret =isUnique(arr);
    printf("ret=%d\n",ret);
    return 0; 
}
