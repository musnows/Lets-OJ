nclude<stdio.h>


int GetMonthDay(int year,int month)
{
    static int mArrnoleap[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    static int mArrleap[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

    if((year%4==0) && (year%100!=0) || (year%400==0))
    {
        return mArrleap[month];
    }
    else
    {
        return mArrnoleap[month];
    }
}

int main()
{
    int n=0;
    int year=0;
    int month=0;
    int day=0;
    int addy=0;

    scanf("%d",&n);
    
    while(scanf("%d%d%d%d",&year,&month,&day,&addy)!=EOF)
    {
        day+=addy;
        while(day>GetMonthDay(year, month))
        {
            day-=GetMonthDay(year,month);
            month++;
            if(month==13)
            {
                year++;
                month=1;
            }
        }
        printf("%4d-%02d-%02d\n",year,month,day);
    }
    return 0;
}

class Solution {
public:
bool isLetter(char ch)
{
    if(ch >= 'a' && ch <= 'z')
    return true;
    else if(ch >= 'A' && ch <= 'Z')
    return true;
    else    
    return false;
}
string reverseOnlyLetters(string s) {
string::iterator itf=s.begin();
string::iterator ite=s.end()-1;

while(itf < ite)
    {
    //cout<<left<<":"<<right<<endl;
    while(itf < ite && !isLetter(*itf))
    ++itf;

    while(itf < ite && !isLetter(*ite))
    --ite;

    swap(*itf, *ite);
    ++itf;
    --ite;
}

return s;
    }
};
