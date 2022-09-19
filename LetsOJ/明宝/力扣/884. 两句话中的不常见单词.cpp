//884. 两句话中的不常见单词
//https://leetcode.cn/problems/uncommon-words-from-two-sentences/

#define _CRT_SECURE_NO_WARNINGS 
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		string s = s1 + ' ' + s2;

		vector<string> v;
		for (size_t i = 0; i < s.size(); i++)
		{
			string word;
			while (i < s.size() && s[i] != ' ')
			{
				word += s[i];
				i++;
			}
			v.push_back(word);

		}

		unordered_map<string, int> m;
		for (auto& str : v)
		{
			m[str]++;
		}

		v.clear();
		for (auto& str : m)
		{
			if (str.second == 1)
				v.push_back(str.first);
		}

		return v;
	}

	void test()
	{
		string s1 = "this apple is sweet", s2 = "this apple is sour";
		uncommonFromSentences(s1, s2);
	}
};

int main()
{
	Solution().test();
	return 0;
}