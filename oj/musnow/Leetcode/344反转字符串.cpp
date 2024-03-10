#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void swapChar(char* a,char* b)
    {
        char temp = *a;
        *a = *b;
        *b = temp;
    }
    void reverseString(vector<char>& s) {
        for(int i =0 ;i<s.size()/2; i++){
            swapChar(&s[i],&s[s.size()-i-1]);
        }
    }
    // 反转字符串
    void reverseString(string& s,int begin, int end) {
        int left = begin;
        int right = end-1;
        while(left < right)
        {
            swapChar(&s[left],&s[right]);
            left ++ ;
            right --;
        }
    }
};
// https://leetcode.cn/problems/reverse-string/
// 最简单的字符串反转题目

// 删除多余空格，保证两个单词之间只有一个空格
void removeSpace(string& s)
{
    int slow = 0;
    int fast = 0;

    // 走到第一个不为空格的地方
    while(fast < s.size() && s[fast] == ' '){
        fast++;
    }

    while(fast < s.size())
    {
        if(fast > 1 
            && s[fast] == s[fast - 1 ]
            && s[fast] == ' ') // 这里判断fast-1也是空格的时候，就会开始跳过，并且第一个空格已经被复制过去了
        {
            fast ++;
            continue;
        }
        else
        {
            s[slow] = s[fast];
            slow++;
            fast++;
        }
    }
    cout << "[" << s <<"]"  << endl << slow << " " << fast << endl;
    // 走到这里的时候，slow一般是在原始字符串的末尾
    // slow走的比fast慢，slow不可能越界

    // 因为fast跳过末尾连续空格的时候，会复制一个空格到slow位置去；
    // slow再++，此时slow所在位置是新字符串单词后的第二个空格处；
    // 如果slow-1的位置是空格，则slow-1就是字符串的长度（长度比下标大1）
    if(slow > 1 && s[slow-1] == ' ')
    {
        s.resize(slow-1);
    }
    else // 如果slow的位置不是空格，则代表它是在原始字符串的末尾单词处
        // 这个单词没有被其他内容复写掉，说明原始字符串末尾是没有多余空格的，那么slow刚好就是字符串的长度
    {
        s.resize(slow);
    }
}

int main()
{
    Solution s;
    // vector<char> v = {'1','2','3','4'};
    // s.reverseString(v);
    // for(auto &e:v)
    // {
    //     cout << e  << " " ;
    // }
    // cout << "\n";
    // string str = "abcdefgh";
    // s.reverseString(str,str.size()-4,str.size()-2);


    string str = " abc   der ";
    removeSpace(str);
    cout << "[" << str <<"]" <<  endl;
}