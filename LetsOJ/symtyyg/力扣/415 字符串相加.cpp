// https://leetcode.cn/problems/add-strings/
//#define _CRT_SECURE_NO_WARNINGS 
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		int end1 = num1.size() - 1;
//		int end2 = num2.size() - 1;
//		string retnum;
//		int carry = 0;
//
//		while (end1 >= 0 || end2 >= 0)
//		{
//			int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
//			int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
//			int ret = val1 + val2 + carry;
//			if (ret > 9)
//			{
//				carry = 1;
//				ret -= 10;
//			}
//			else
//				carry = 0;
//			//retnum.insert(retnum.begin(),ret+'0');
//			retnum += ('0' + ret);// Î²²åĞ§ÂÊ¸ß
//		}
//		if (carry == 1)
//			//retnum.insert(retnum.begin(),'1');
//			retnum += '1';
//
//		reverse(retnum.begin(), retnum.end());
//		return retnum;
//	}
//};