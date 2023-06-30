//345. 反转字符串中的元音字母

// https://leetcode.cn/problems/reverse-vowels-of-a-string/description/
class Solution {
    bool isVowel(char ch)
    {
        string vowels = "aeiouAEIOU";
        return vowels.find(ch)!=string::npos;
    }
public:
    string reverseVowels(string s) {
        int n = s.size();
        int left = 0, right = n-1;
        while(left<right)
        {
            while(left<n && !isVowel(s[left]))
                left++;
            while(right>0 && !isVowel(s[right]))
                right--;
            if(left<right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;

    }
}
