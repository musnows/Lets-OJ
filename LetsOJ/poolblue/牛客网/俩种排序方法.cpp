#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>


using namespace std;

bool IsLexSort(vector<string>& arr)
{
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i - 1] >= arr[i]) {
            return  false;

        }
        return true;
    }
}
bool IsLenthSort(vector<string>& arr)
{

    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1].size() >= arr[i].size())
            return false;


    }
    return true;

}
int main()
{
    int n = 0;
    vector<string> arr;
    while (cin >> n)
    {
        arr.resize(n);
        for (auto& str : arr)
        {
            cin >> str;
        }
        if (IsLenthSort(arr) && IsLexSort(arr))
            cout << "both" << endl;
        else if (IsLenthSort(arr) && !IsLexSort(arr))
            cout << "lengths" << endl;
        else if (!IsLenthSort(arr) && IsLexSort(arr))
            cout << "lexicographically" << endl;
        else if (!IsLenthSort(arr) && !IsLexSort(arr))
            cout << "none" << endl;

    }

    return 0;
}

