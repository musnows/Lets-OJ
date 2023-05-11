//HJ7 取近似值
//https://www.nowcoder.com/practice/3ab09737afb645cc82c35d56a5ce802a?tpId=37&&tqId=21230&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
//写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于 0.5 ,向上取整；小于 0.5 ，则向下取整。
//数据范围：保证输入的数字在 32 位浮点数范围内

#include<stdio.h>

int main()
{
    float f1;
    scanf("%f",&f1);
    int num=(int)f1;
    //printf("%f %d\n",f1,num);
    float ret=f1-(float)num;
    //printf("%f %d\n",ret,num);
    if(ret>=0.5){
        num++;
    }
    printf("%d\n",num);
    
    return 0;
}
