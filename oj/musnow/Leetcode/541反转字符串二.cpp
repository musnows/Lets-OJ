class Solution {
public:
    void swapChar(char* a,char* b)
    {
        char temp = *a;
        *a = *b;
        *b = temp;
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

    string reverseStr(string s, int k) {
        if(s.size() <= k)
        {
            reverseString(s,0,s.size());
            return s;
        }
        size_t size = s.size();
        size_t i = 0;
        for(i=0;i<size;i+=2*k)
        {
            if(size - i < k){
                // 小于k则全部逆置
                reverseString(s,i,size);
            }
            else{
                reverseString(s,i,i+k);
            }
            //cout << i << " - " << s << endl;
        }


        // 下面这些思路是错误的，循环走完不会多出来
        // size_t left = size % (2*k);
        // cout << "left " << left << endl;
        // // 如果在k到2k之间
        // // 如果left为0，则代表刚好整除k，此时还会剩下一个
        // if(left == 0 || (left >= k && left<2*k))
        // {
        //     reverseString(s,size-(2*k),size-k);
        // }
        // // 如果小于k
        // if(left >0&& left <k )
        // {
        //     reverseString(s,size-(2*k),size); // 最后的都反转
        // }
        return s;
    }
};

// https://leetcode.cn/problems/reverse-string-ii/
// 使用区间反转函数来处理就行了