//WY20 两种排序方法
////https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void StringType(vector<string>v)
{
    bool flagDict = true, flagLength = true;
    auto it = v.begin();
    while (it != v.end())
    {
        auto temp = it;
        it++;
        //it已经是end，说明temp是最后一个数据
        if (it == v.end()) {
            break;//这种情况不用继续进行比较
        }
        //比较size，如果temp>it的size说明非长度序
        if ((*temp).size() > (*it).size())
        {
            flagLength = false;
        }
        //比较字典序，如果temp字典序先于it，返回负数
        //相同返回0； temp后于it返回正数
        int com = (*temp).compare(*it);
        if (com > 0)
        {
            flagDict = false;
        }
    }


    if (flagLength && flagDict)
    {
        cout << "both" << endl;
    }
    else if (flagDict) {
        cout << "lexicographically" << endl;
    }
    else if (flagLength) {
        cout << "lengths" << endl;
    }
    else {
        cout << "none" << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    char arr[102] = "0";
    while (scanf("%s", arr) != EOF)
    {
        string temp(arr);
        v.push_back(temp);
    }

    StringType(v);

    return 0;
}
