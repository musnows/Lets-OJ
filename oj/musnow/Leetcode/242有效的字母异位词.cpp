class Solution {
public:

    // 因为题目中提到只有小写字母，所以用一个int[26]数组就能实现
    // 这里用hash map也是一样的道理，思路完全一致。
    bool isAnagram(string s, string t) {
        unordered_map<char,int> maps;
        for(auto&e:s)
        {
            if(!maps.count(e))
            {
                maps[e] = 1;
            }
            else
            {
                maps[e]++;
            }
        }

        for(auto&e:t)
        {
            if(!maps.count(e)){
                return false;
            }
            maps[e]--;
        }

        for(auto&e:maps)
        {
            if(e.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};