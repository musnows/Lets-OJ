//#define _CRT_SECURE_NO_WARNINGS 1
////#include <stdio.h>
//#include <iostream>
//using namespace std;
////917. 仅仅反转字母
////https://leetcode.cn/problems/reverse-only-letters/submissions/
//class Solution {
//public:
//    bool isLetter(char s)
//    {
//        if (s >= 'a' && s <= 'z') {
//            return true;
//        }
//        else if (s >= 'A' && s <= 'Z') {
//            return true;
//        }
//        return false;
//    }
//    string reverseOnlyLetters(string s) {
//        int left = 0, right = s.size() - 1;
//        while (left < right)
//        {
//            //只要遇到不是字母的，就跳过
//            //用left<right保证不越界
//            while (left < right && !isLetter(s[left])) {
//                left++;
//            }
//            while (right > left && !isLetter(s[right])) {
//                right--;
//            }
//            //直接调用库函数中的swap进行交换，不用自己写
//            swap(s[left], s[right]);
//            left++;
//            right--;
//        }
//        return s;
//    }
//};