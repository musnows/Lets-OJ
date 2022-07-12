//43. 字符串相乘
//https://leetcode.cn/problems/multiply-strings/
//我是看题解做的↓ 自己实在想不出来
//https://leetcode.cn/problems/multiply-strings/solution/si-lu-qing-xi-by-lllllliuji-2/

//给题解上了注释，更好看懂
class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        vector<int> a, b, c;
        c.resize(num1.size() + num2.size() - 1);//c为初步结果
        //先将a和b（即需要相乘的两个数改为vector数组
        for (int i = num1.size() - 1; i >= 0; i--) 
            a.push_back(num1[i] - '0');
        for (int i = num2.size() - 1; i >= 0; i--) 
            b.push_back(num2[i] - '0');
        //通过嵌套for进行每一位单独和另外一个数的相乘，得到的答案存入c
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++) 
            {
                c[i + j] += a[i] * b[j];
            }
        }
        //利用k得到每一位的字符
        int k = 0;
        for (int i = 0; i < c.size(); i++) {
            k += c[i];//直接和前一位相乘
            char c = k % 10 + '0';//个位
            ans = c + ans;//头插
            k /= 10;//得到十位的数
        }
        //如果结果的c已经遍历完（代表数据已经走完了）k还没有处理干净（即k>10)
        while (k) {
            char c = k % 10 + '0';//个位
            ans = c + ans;//头插
            k /= 10;//十位
        }
        //因为是c+ans的头插，所以可能会出现前导0
        //比如k=20，此时k%10=0，c=0，会导致ans头部有多余的0
        while (ans.size() > 1 && ans[0] == '0') 
        {
            ans.erase(ans.begin());//删除前面的前导0
        }
        return ans;
    }
};
