//https://leetcode.cn/problems/determine-if-string-halves-are-alike/ 
class Solution {
public:
    bool halvesAreAlike(string s) {
        //划分长度相同的字符串
        string a = s.substr(0, s.size() / 2);
        string b = s.substr(s.size() / 2);
        //元音字符串
        string h = "aeiouAEIOU";
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < a.size(); i++) {
            if (h.find_first_of(a[i]) != string::npos) {//遍历元音字符串，判断字符是不是元音
                sum1++;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (h.find_first_of(b[i]) != string::npos) {//同上
                sum2++;
            }
        }
        return sum1 == sum2;//相似返回返回 true ；否则，返回 false
    }
};


