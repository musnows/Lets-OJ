//https://leetcode.cn/problems/recursive-mulitply-lcci/submissions/
//面试题 08.05. 递归乘法
//乘法本质上就是A个B相加
int _multiply(int A, int B,int* p){
    if(A<=0){
        return (*p);
    }
    else{
        (*p)+=B;
        A--;
    }
    return _multiply(A,B,p);
}

int multiply(int A, int B){
    int ret=0,min=A,max=B;
    //为了避免递归调用太多，这里需要将小的那个数作为递归条件
    //大的那个数作为相加的操作数
    if(A>B){
        min=B;
        max=A;
    }
    _multiply(min,max,&ret);//才用传址调用可以直接修改ret
    return ret;
}
