using namespace std;
#include <vector>
#include <algorithm>//sort

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        vector<int> v(numbers);//拷贝构造
        sort(v.begin(),v.end());//排序
        return v[v.size()/2];//排序后的中位数就是超过一半的数字
    }
};

//给定一个数组，其中有个数字超过了这个数组长度的一半
//1 2 3 2 2 4 2 2
//2有5个超过一半，输出2