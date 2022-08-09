// HJ99 自守数
// https://www.nowcoder.com/practice/88ddd31618f04514ae3a689e83f3ab8e?tpId=37&&tqId=21322&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
// 自守数是指一个数的平方的尾数等于该数自身的自然数。例如：25^2 = 625，76^2 = 5776，9376^2 = 87909376。请求出n(包括n)以内的自守数的个数
// 数据范围：1≤n≤10000 
#include<math.h>
//gcc编译math.h报错，需要在结尾加上-lm
int countN(int n)//计算整数的长度
{
    int count=0;
    while(n>0)
    {
        n/=10;
        count++;
    }
    return count;
}

int main()
{
    int n;
    scanf("%d",&n);
    int sum;//存放结果
    int i =0;
    for(i=0;i<=n;i++)
    {
        int num=i;
        long p=pow(num,2);//获得平方后的结果
        int c = countN(num);//得到该数长度
        while(c--)
        {
            if(p%10==num%10)//进行比较，如果一样那就同时/10
            {
                p/=10;
                num/=10;
            }
            else{
                break;//不一样就退出循环
            }
        }
        //只有c<0代表走完了循环，sum+1
        if(c<0)
        {
            sum++;
        }
    }

    printf("%d\n",sum);    

    return 0;
}
