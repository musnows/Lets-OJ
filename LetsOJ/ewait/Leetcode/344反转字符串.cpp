//344. 反转字符串
//https://leetcode.cn/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        //1.下标
        // int right = s.size()-1;
        // int left = 0;
        // while(left<right)
        // {
        //     swap(s[left],s[right]);
        //     left++;
        //     right--;
        // }


        //2.迭代器
        auto right =s.end()-1;
        auto left =s.begin();
        while(left<right)//用!=会栈溢出？
        {
            swap(*left,*right);
            left++;
            right--;
        }
        return ;
    }
};