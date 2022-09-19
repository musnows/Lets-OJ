tor<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> m;
    vector<string> v1;
    auto it = s1.begin();
    auto begin = s1.begin();
    while (it != s1.end())
    {
        if (*it == ' ')
        {
            string temp(begin, it);
            //v1.push_back(temp);
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

    string temp1(begin, it);
    auto fd = m.find(temp1);
    if (fd != m.end())
    {
        fd->second++;
    }
    else
    {
        m.insert(make_pair(temp1, 1));
    }

    //v1.push_back(temp);
    for (auto e : m)
    {
        cout << e.first << "_" << e.second << " ";
    }
    cout << endl;

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
                //v1.push_back(temp);
            }
            begin = ++it;
        }
        else
        {
            it++;
        }
    }

    string temp2(begin, it);
    fd = m.find(temp2);
    if (fd == m.end())
    {
        m.insert(make_pair(temp2, 1));
        //v1.push_back(temp2);
    }
    else
    {
        fd->second++;
    }

    for (auto e : m)
    {
        cout << e.first << "_" << e.second << " ";
        if (e.second == 1)
        {
            v1.push_back(e.first);
        }
    }
    cout << endl;


    return v1;
}
//884. 两句话中的不常见单词
//https://leetcode.cn/problems/uncommon-words-from-two-sentences/
