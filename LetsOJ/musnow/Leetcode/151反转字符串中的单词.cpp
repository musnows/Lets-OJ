class Solution {
public:
    //从begin开始找到下一个空格的下标，不包括begin本身
    int find_space(string&s,int begin=0)
    {
        int i=0;
        for(i=begin+1;i<s.size();i++)
        {
            if(s[i]==' '){
                return i;
            }
        }
        return s.npos;
    }

    string reverseWords(string s) {
        int i=0;
        vector<string> v;//用来存放单词
        for(i=0;i<s.size();i++)
        {
            // 跳过前导空格
            while(s[i]==' '){
                i++;
            }
            // 如果已经到最后面了，就直接跳出
            if(i>=s.size()){
                break;
            }
            int index = find_space(s,i);
            int sz = index-i;//单词长度
            //cout << i << " | " << index << " | "<< sz << endl;
            string temp(s,i,sz);
            //cout << temp << "-" << endl;
            v.push_back(temp);//插入单词
            i = index-1;//跳过当前单词
        }
        //反向迭代器
        auto it = v.rbegin();
        string ret = "";
        while(it!=v.rend())
        {
            ret+=*it;
            // 不是倒数第一个才加空格
            if(++it!=v.rend()){
                ret+=" ";
            }
        }
        cout << ret << endl;
        return ret;
    }
};
//https://leetcode.cn/problems/reverse-words-in-a-string/
//上面的办法中，新增了一个vector来拼接字符串，空间复杂度O(N)
//24MS 7.1MB

//进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。

//版本2，原地算法，通过
class Solution {
public:
    #define SEP '|'
    //从begin开始找到下一个空格的下标，不包括begin本身
    int find_space(string&s,int begin=0)
    {
        int i=0;
        for(i=begin+1;i<s.size();i++)
        {
            if(s[i]==' '){
                break;
            }
            else if(s[i]==SEP)
            {//用一个特殊字符作为原字符串结尾
                break;
            }
        }
        //如果是因为找到空格跳出，判断该字符串后面还有没有有效字符
        int k = i;//不能改i
        if(s[k]!=SEP)
        {
            while(s[k]==' ')
            {
                k++;
                //一直走到了|，代表没有有效字符了
                if(s[k]==SEP){
                    return s.npos;
                }
            }
            //走到这里代表有
            return i;
        }

        return s.npos;
    }

    string reverseWords(string s) {
        int i=0,end_word=0,index=0;
        int begin_sz = s.size();//起始大小
        s+=SEP;//用一个特殊字符作为原字符串结尾
        int sep_index = s.size()-1;//最后一个字符的位置就是分隔符
        
        for(i=0;i<begin_sz;i++)
        {
            // 跳过前导空格
            while(s[i]==' '){
                i++;
            }
            // 如果已经到最后面了，就直接跳出
            if(i>=begin_sz){
                break;
            }
            index = find_space(s,i);
            //如果找不到下一个空格了，代表当前是原字符串最后一个单词
            //跳过
            if(index == s.npos){
                end_word=i;
                break;
            }
            int sz = index-i;//单词长度
            string temp(s,i,sz);
            temp+=" ";
            //不能尾插，应该在sep之后插入
            //s += temp;
            s.insert(sep_index+1,temp);

            // cout << i << " | " << index << " | "<< sz << endl;
            // cout << temp << "-" << endl;

            //构造了之后，把原str这部分删了(错误！删了之后下标变了，循环无意义)
            //s.erase(i,sz);

            i = index-1;//跳过当前单词
            //index-1是因为本次循环过了之后会被for给+1
        }
        cout <<"[end]"<< s << endl;
        // 字符串中添加的|替换为空格
        index = s.find(SEP);
        
        // 删除index之前,end_word之后的空格
        int k = s.find(" ",end_word);
        //cout << "k:" <<k<<" endw:" << end_word <<endl;
        if(k!=s.npos&&k<index){
            s.replace(k,1,"");
            index--;
            //cout <<"[while1]k:"<<k <<" str:"<< s << endl;
            //因为替换过了之后，k的位置变成了原有k的下一位
            //此时如果k还是空格，代表原字符串末尾有多个空格
            //继续删除，但是每次删除都需要让sep的位置-1
            while(s[k]==' '){
                s.replace(k,1,"");
                index--;
            }
            //跳出这个循环的时候，代表碰到sep分隔符了,字符串已经处理完毕
            //cout <<"[while2]k:"<<k <<" str:"<< s << endl;
        }
        s.replace(index,1," ");
        s.erase(0,end_word);//删掉前面的原有单词
        s.erase(s.size()-1,1);//删除最后单词带的空格
        return s;
    }
};
//4MS 7MB