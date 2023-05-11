//541. 反转字符串 II
//https://leetcode.cn/problems/reverse-string-ii/
class Solution {
public:
    void reverseString(string& s,int begin,int end)
    {
        // if(begin<end){
        //     return ;
        // }
        //逆置字符串
        int right = end;
        int left = begin;
        while(left<right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return ;
    }
    string reverseStr(string s, int k) {
        int left=0;
        int pos=2*k-1;
        while(pos<=s.size())
        {
            reverseString(s,left,left+k-1);
            left=pos+1;
            pos+=2*k;
        }
        if(s.size()-left>=k)
        {
           reverseString(s,left,left+k-1);
        }
        else{//剩余少于k，则反转剩余的全部字符串
            reverseString(s,left,s.size()-1);
        }
        return s;
    }
};