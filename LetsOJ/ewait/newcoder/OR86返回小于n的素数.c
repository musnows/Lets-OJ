//OR86 返回小于 N 的质数个数
//https://www.nowcoder.com/practice/9e7a88d6a00e404c8418602515a5046c?tpId=182&&tqId=34812&rp=1&ru=/ta/exam-all&qru=/ta/exam-all/question-ranking
//试除法判断素数 https://blog.csdn.net/muxuen/article/details/121049495
#include<math.h>
#include<stdio.h>
int main()
{
	int i,n;
    int count=0;
    scanf("%d",&n);    
	for(i=2;i<=n;i++)
	{
		int j=0;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				break;
             }
		}
		if(j>sqrt(i))
		{
			count++;
            //printf("%d ",i);
		}
	}
    printf("%d\n",count);

	return 0;
}
