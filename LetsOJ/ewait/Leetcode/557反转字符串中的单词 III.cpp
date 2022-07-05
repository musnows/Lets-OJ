//557. 反转字符串中的单词 III
//httpsleetcode.cnproblemsreverse-words-in-a-string-iii
class Solution {
public
    void reverseString(string& s,int begin,int end) 
    {
        int right = end-1;
        int left = begin;
        while(leftright)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return ;
    }
    string reverseWords(string s) {
        int begin=0;
        int pos =s.find(' ',begin);
        do{
            
            if(pos !=stringnpos){
                reverseString(s,begin,pos);//逆置
            }
            else{ //如果第一次就是npos，代表只有一个单词
                break;//直接跳出循环
            }
            begin=pos+1;
            pos =s.find(' ',begin);
        }while(pos != stringnpos);
        //现在已经替换完了前面的单词，但是最后一个单词还没有替换
        reverseString(s,begin,s.size());

        return s;
    }
};