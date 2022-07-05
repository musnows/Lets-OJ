#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
#include <iostream>
using namespace std;
//125. 验证回文串
//https://leetcode.cn/problems/valid-palindrome/submissions/

class Solution {
public:
    bool isLN(char s)//判断是否为字母或者数字
    {
        if (s >= 'a' && s <= 'z') {
            return true;
        }
        else if (s >= 'A' && s <= 'Z') {
            return true;
        }
        else if (s >= '0' && s <= '9')
            return true;

        return false;
    }
    void reverseString(string& s, int begin, int end)
    {
        //逆置字符串
        int right = end;
        int left = begin;
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return;
    }
    bool isPalindrome(string s) {
        string temp;//提取出只含数字字母的版本
        for (int i = 0; i < s.size(); i++)
        {
            if (isLN(s[i]))
            {
                temp += s[i];
            }
        }
        cout << temp << endl;

        string rtemp(temp);
        reverseString(rtemp, 0, rtemp.size() - 1);
        cout << rtemp << endl;

        int n = 0;
        while (n < temp.size())
        {
            //比较的时候需要忽略大小写
            
            if (temp[n] != rtemp[n]) {
                if (((temp[n] - 32) != rtemp[n]) && ((temp[n] + 32) != rtemp[n])) {
                    return false;
                }
                else if ((temp[n] == 'P' && rtemp[n] == '0') || (rtemp[n] == 'P' && temp[n] == '0'))
                { //注意0零和P的情况，正好也是差32！！！
                    return false;
                }
            }
            n++;
        }
        return true;
    }
};

int main()
{
    string s("0P");//这个是零和P！！！不是英文OP
    Solution k;
    //cout << true << " " << false << endl;
    int ret=k.isPalindrome(s);
    cout << "ret: " << ret << endl;
    return 0;
}