class Solution {
public:
    //https://leetcode.cn/problems/uncommon-words-from-two-sentences/
    //884两句话中的不常见单词
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;//哈希表
        vector<string> v1;//返回值

        // 1.先遍历第一个string，把数据插入进去
        auto it = s1.begin();
        auto begin = s1.begin();
        while (it != s1.end())
        {
            if (*it == ' ')//以空格作为分割
            {
                string temp(begin, it);//构造一个string进行插入
                auto fd = m.find(temp);//在m里面找
                if (fd != m.end())//找到了
                {
                    fd->second++;//次数++
                }
                else
                {//找不到，执行插入
                    m.insert(make_pair(temp, 1));
                }
                begin = ++it;//前置++ 更新begin（否则会从空格开始）
            }
            else
            {
                it++;//不是空格继续++
            }
        }
        //遍历完之后，最后一个单词没有操作
        string temp1(begin, it);//构造最后一个单词
        auto fd = m.find(temp1);//查找
        if (fd != m.end())//找到了，次数+1
        {
            fd->second++;
        }
        else
        {
            m.insert(make_pair(temp1, 1));//找不到，插入
        }

        //打印当前map的结果（用于测试）
        //for (auto e : m)
        //{
        //    cout << e.first << "_" << e.second << " ";
        //}
        //cout << endl;

        // 2.遍历第二个string，思路完全同上
        it = s2.begin();
        begin = s2.begin();
        while (it != s2.end())
        {
            if (*it == ' ')
            {
                string temp(begin, it);
                auto fd = m.find(temp);
                if (fd != m.end())
                {
                    fd->second++;
                }
                else
                {
                    m.insert(make_pair(temp, 1));
                }
                begin = ++it;
            }
            else
            {
                it++;
            }
        }
        //操作最后一个单词，思路同上
        string temp2(begin, it);
        fd = m.find(temp2);
        if (fd == m.end())
        {
            m.insert(make_pair(temp2, 1));
        }
        else
        {
            fd->second++;
        }

        //3.最后遍历map，找到次数为1的单词，插入进返回值
        for (auto e : m)
        {
            cout << e.first << "_" << e.second << " ";
            if (e.second == 1)
            {
                v1.push_back(e.first);
            }
        }
        //返回结果
        return v1;
    }
};