//HJ55 挑7
//https://www.nowcoder.com/practice/ba241b85371c409ea01ac0aa1a8d957b?tpId=37&&tqId=21278&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
//输出 1到n之间 的与 7 有关数字的个数。
//一个数与7有关是指这个数是 7 的倍数，或者是包含 7 的数字（如 17 ，27 ，37 ... 70 ，71 ，72 ，73...）
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdbool.h>

bool IF7in(int n)
{
    int k=0;
    while(n>0)
    {
        int tmp=n%10;
        if(tmp==7){
            return true;
        }
        n/=10;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    int count=0;
    for(i=7;i<=n;i++){
        if(i%7==0)
        {
            count++;
            //printf("%d ",i);
        }
        else if(IF7in(i))
        {
            count++;
            //printf("%d ",i);
        }
    }
    printf("%d",count);
    return 0;
}
