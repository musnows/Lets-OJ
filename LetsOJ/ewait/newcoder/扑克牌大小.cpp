#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

void Solusion()
{
    map<string, int> card = {
        {"3", 1},
        {"4", 2},
        {"5", 3},
        {"6", 4},
        {"7", 5},
        {"8", 6},
        {"9", 7},
        {"10", 8},
        {"J", 9},
        {"Q", 10},
        {"K", 11},
        {"A", 12},
        {"2", 13},
        {"joker", 14},
        {"JOKER", 15}
    };
    vector<string> s1;
    vector<string> s2;
    //s.resize(11);
    string tmp;
    int flag = 0;
    while (cin >> tmp) {
        size_t found = tmp.find("-");
        if (found != string::npos) {
            string temp1(tmp, 0, found);
            s1.push_back(temp1);
            string temp2(tmp, found + 1, tmp.size() - found);
            s2.push_back(temp2);
            flag = 1;
        } else {
            if (flag == 0) {
                s1.push_back(tmp);
            } else {
                s2.push_back(tmp);
            }
        }

    }
    
    //判断是否存在王对，这个是最大的
    if(s1.size()>=2 and s2.size()>=2)
    {
        if ((s1[0] == "joker" and s1[1] == "JOKER") 
            || (s1[1] == "joker" and s1[0] == "JOKER") )
        {//s1是大王对
            for(auto&e:s1){
                 cout << e <<" ";
            }
            return ;
        }
        else if((s2[0] == "joker" and s2[1] == "JOKER") 
            || (s2[1] == "joker" and s2[0] == "JOKER"))
        {//s2是大王对
            for(auto&e:s2){
                 cout << e <<" ";
            }
            return ;
        }
    }
    //判断是否存在炸弹(一个是4另外一个不是)
    if(s1.size()==4 && s2.size()!=4)
    {
       string comp =s1[0];
       auto it = s1.begin();
       while(it != s2.end())
       {
           if((*it)!=comp){
               break;
           }
           else{
               comp=*it;
           }
           it++;
       }
       if(it==s1.end())
       {
           for(auto&e:s1){
                 cout << e <<" ";
           }
           return ;
       }
    }
    else if(s2.size()==4&& s1.size()!=4)
    {
       string comp =s2[0];
       auto it = s2.begin();
       while(it != s2.end())
       {
           if((*it)!=comp){
               break;
           }
           else{
               comp=*it;
           }
           it++;
       }
       if(it==s2.end()){
           for(auto&e:s2){
                 cout << e <<" ";
           }
           return ;
       }
    }
    
    //单子比较
    if(s1.size()==1 && s2.size()==1)
    {
        if(card[s1[0]] <= card[s2[0]]){
            for(auto&e:s2){
                 cout << e <<" ";
            }
            return ;
        }
        else if(card[s2[0]] <= card[s1[0]]){
            for(auto&e:s1){
                 cout << e << " ";
            }
            return ;
        }
    }
    //对子比较
    if (s1.size() == 2 && s2.size() == 2) 
    {
        
        if(card[s1[0]] <= card[s2[0]]){
            for(auto&e:s2){
                 cout << e <<" ";
            }
            return ;
        }
        else if(card[s2[0]] <= card[s1[0]]){
            for(auto&e:s1){
                 cout << e << " ";
            }
            return ;
        }
    }
    //三个比较
    if(s1.size()==3 && s2.size()==3)
    {
        if(card[s1[0]] <= card[s2[0]]){
            for(auto&e:s2){
                 cout << e <<" ";
            }
            return ;
        }
        else if(card[s2[0]] <= card[s1[0]]){
            for(auto&e:s1){
                 cout << e << " ";
            }
            return ;
        }
    }
    //炸弹比较
    if(s1.size()==4 && s2.size()==4)
    {
        if(card[s1[0]] <= card[s2[0]]){
            for(auto&e:s2){
                 cout << e <<" ";
            }
            return ;
        }
        else if(card[s2[0]] <= card[s1[0]]){
            for(auto&e:s1){
                 cout << e << " ";
            }
            return ;
        }
    }
    //顺子比较(只用看最小的牌，用例中已经排序)
    if(s1.size()==5 && s2.size()==5)
    {
        if(card[s1[0]] <= card[s2[0]]){
            for(auto&e:s2){
                 cout << e <<" ";
            }
            return ;
        }
        else if(card[s2[0]] <= card[s1[0]]){
            for(auto&e:s1){
                 cout << e << " ";
            }
            return ;
        }
    }
    
    //前面没有return，说明有问题
    cout << "ERROR" <<endl;
}

int main() 
{
    Solusion();
    
    return 0;
}

//新大陆！！C++尽然支持and和or，甚至还支持not
//https://www.nowcoder.com/questionTerminal/d290db02bacc4c40965ac31d16b1c3eb?commentTags=C%2FC%2B%2B
//牛客网
