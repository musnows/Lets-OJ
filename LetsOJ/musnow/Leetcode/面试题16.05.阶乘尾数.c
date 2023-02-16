//面试题 16.05. 阶乘尾数
//https://leetcode.cn/problems/factorial-zeros-lcci/
//设计一个算法，算出 n 阶乘有多少个尾随零。

//第一个方法是直接算递归，但是这个在数据很大的时候压根用不了
//超时!
long long factoria(long long*p,int n)
{
    if(n<=0){
        return (*p);
    }
    (*p)*=n;
    n--;
    return factoria(p,n);
}


int trailingZeroes1(int n){
    long long ret=1;
    factoria(&ret,n);
    printf("%lld\n",ret);
    int count=0;
    while(ret>0)
    {
        int tmp=ret%10;
        if(tmp==0){
            count++;
        }
        else{
            break;
        }
        ret/=10;
    }
    return count;
}

//方法2
//递归结果后面0的个数其实就是因数中5的个数
//因为只有偶数*5才会出现0
int trailingZeroes(int n){
    int ret = 0;
    while (n) 
    {
        n /= 5;
        ret += n;        
    }
    return ret;
}
