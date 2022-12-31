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


//22.12.31第二次写这道题
//不同的解决方案
class Solution {
public:
    void ReverString(vector<char>& tmp,string& ret)
    {
        auto rit = tmp.rbegin();
        while(rit!=tmp.rend())
        {
            //cout << (*rit);
            ret+=(*rit);
            rit++;
        }
        tmp.resize(0);//清空vector
    }

    string reverseWords(string s) {
        vector<char> tmp;
        string ret="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                tmp.push_back(s[i]);
            }
            else
            {//遇到空格，就逆序添加vector中以有内容
                ReverString(tmp,ret);
                ret+=" ";//添加空格
            }
        }
        ReverString(tmp,ret);//最后一个单词
        return ret;
    }
};