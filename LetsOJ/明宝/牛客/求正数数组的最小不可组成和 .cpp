//https://www.nowcoder.com/questionTerminal/296c2c18037843a7b719cf4c9c0144e4
//求正数数组的最小不可组成和 
#include <iostream>
using namespace std;
#include <vector>

int getFirstUnFormedNum(vector<int> arr, int len) {
    int min = arr[0], max = 0;
    for(auto e:arr)
    {
        if(min>e)
            min = e;
        
        max+=e;
    }
    
    vector<int> dp(max+1, 0);
    for(int i = 0; i<len; i++)
    {
        for(int j = max; j>=arr[i]; j--)
        {
            if(dp[j] < dp[j-arr[i]] + arr[i])
            {
                dp[j] = dp[j-arr[i]] + arr[i];
            }
        }
    }
    
    
    for(int i = min; i<max; i++)
    {
        if(dp[i] != i)
        {
            return i;
        }
    }
    return max+1;
}

int main()
{
    vector<int> arr {2,3,5};
    cout<<getFirstUnFormedNum(arr, 3)<<endl;
}
