//https://leetcode.cn/problems/add-strings/
//415. 字符串相加

class Solution {
public:
    void reverseString(string& s) 
    {
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
    string addStrings(string num1, string num2) {
        int end1=num1.size()-1;
        int end2=num2.size()-1;
        int c=0;//表示是否进位
        string s;//返回对象
        while(end1>=0||end2>=0){
            int val1 = end1>=0?num1[end1]-'0':0;
            int val2 = end2>=0?num2[end2]-'0':0;
            int ret =val1+val2+c;
            if(ret>9){
                ret-=10;
                c=1;
            }
            else{
                c=0;
            }
            end1--;
            end2--;
            char c=ret+'0';
            s+=c;//尾插结果
        }
        //如果两个字符串已经走完，还有需要进位的内容，则尾插1
        if(c==1){
            s+='1';
        }
        
        reverseString(s);//因为是尾插，所以需要逆置
        return s;
    }
};