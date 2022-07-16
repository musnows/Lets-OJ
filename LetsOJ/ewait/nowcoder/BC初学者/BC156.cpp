//BC156 牛牛的数组匹配
//https://www.nowcoder.com/practice/3d3406f4a7eb4346b025cc592be5b875?tpId=290&tqId=2370143&ru=/exam/oj/ta&qru=/ta/beginner-programmers/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D290

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

//思路：先把数组b相加得出和，再从末尾开始减，每一次相减都记录一次差值
//如果差值比最初的差值（即完整的b-a）小，就替换掉
//直到减到只剩首位数字（第一论循环结束）
//
//第二轮循环从第二位开始求到末尾和，再从末尾开始减，由此循环

int Find(int* ret,int* a2,int sz,int sum1)
{
    int j=0;
    int d=10000;//设置默认的差值，用于比较
    int begin1=0,end1=sz-1;//记录子数组的起始位置和末位置
    //注意，这里需要分开设置循环内和循环外的变量
    //因为循环类的if会在已经得出正确答案之后继续遍历修改掉正确的begin和end
    while(j < sz)
    {
       int begin = j, end = sz - 1;//这里要从j开始，到sz结束
       //因为如果不从j开始，后续如果无需相减的时候就是最小差值，那么begin每次都是从0开始就会出现问题
       //比如用例
       //5 6
       //21 14 27 42 31
       //7 24 13 21 47 32
       //这里在走到第二层循环，j=1的时候，就已经得出了最后结果24 13 21 47 32
       //但由于默认的begin我设置成了0，结果打印出了7 24 13 21 47 32
       //只要设置成 begin = j就可以了
       int sum=0;
       for(int i=j;i < sz;i++){
           sum+=a2[i];
       }
       
       int diff=abs(sum-sum1);//保存差值
       for(int i=sz-1;i > j;i--){
           sum-=a2[i];//从末尾开始减
           int temp=abs(sum-sum1);//得到本次操作的差值
           if(temp < diff){
               diff=temp;
               begin = j;
               end = i - 1;
           }
       }
       //只有比外部的最小差值还小的时候，才会进行拷贝操作
       if(diff < d){
            //cout<<diff<<endl;
            //cout << begin << " " << end << endl;
            d=diff; 
            memcpy(ret, a2 + begin, (end - begin + 1) * sizeof(int));
            //只有内部得到了更小的差值的时候，才会修改循环体外部的始末位置
            begin1 = begin;
            end1 = end;
       }
       j++;
    }
   // cout<< "d:" << d <<endl;
    return end1-begin1+1;
}

int main()
{
    int n,m;
    cin >> n >>m;
    int * a1=new int[n];
    int * a2=new int[m];
    int sum1=0;
    for(int i=0;i < n;i++){
        cin >>a1[i];
    }
    for(int i=0;i < n;i++){
        sum1+=a1[i];//数组a1相加
    }
    int sum2=0; 
    for(int i=0;i < m;i++){
        cin >>a2[i];
    }

    int* ret=new int[m];//保存子数组
    int num=Find(ret,a2,m,sum1);
    for(int i=0;i < num;i++){
        cout<< ret[i] <<" ";
    }
    
        
    return 0;
}
