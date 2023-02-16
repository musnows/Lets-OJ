#include<iostream>
#include <vector>
using namespace std;

bool isLongYear(int y)
{
    if(y%4==0 && y%100!=0){
        return true;
    }    
    else if(y%400 == 0){
        return true;
    }
    return false;
}

int main()
{   
    int y,m,d;
    vector<int> date = {0,31,59,90,120,151,181,212,243,273,304,334,365};
    while(cin >> y >> m >> d){
        int islong = 0;//闰年
        if(isLongYear(y)){
            islong = 1;//多加一天
        }

        if(m>=3){//二月往上，输出前一个月的天数+当前的d
            cout << date[m-1]+islong+d << endl;
        }
        else{//一/二月份直接输出d+前一个月天数（因为二月不需要加闰年的1）
            cout << date[m-1] + d << endl;
        }
    }
    
    return 0;
}
