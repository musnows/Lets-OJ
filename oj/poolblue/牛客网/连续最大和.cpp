//连续最大和
#include<iostream>
#include <vector>
using namespace std;
int main()
{
    int  n=0;
    int number=0;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)//将每个元素插入数组
    {  
        cin >> number;
        v.push_back(number);
     }
    int maxsum = 0;//记录最大和
    int sum = 0;//记录当前和
    for (auto num : v)//遍历
    {
        sum += num;
        if (sum < num)//如果和比当前数字还小，证明最大和与前面子元素无关
        {
            sum = 0;//置零
            sum += num;//重新加上当前数字，继续往后判断
        }
        if (sum > maxsum)//如果大于最大和，则更新最大和
            maxsum = sum;
    }
    cout << maxsum << endl;

    return 0;
} 
