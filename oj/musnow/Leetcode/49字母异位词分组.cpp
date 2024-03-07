// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

// 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if(strs.size() <=1){
            ret.push_back(strs);
            return ret;
        }

        // 将字符串进行排序，然后判断是否相等
        unordered_map<string,vector<string>> m;
        for(auto&s :strs)
        {
            string key = s;
            sort(key.begin(),key.end());
            m[key].push_back(s); // 排序后的字符串作为key，字母异位词的排序后一定相同
        }
        
        for(auto&v:m)
        {
            ret.push_back(v.second);
        }
        return ret;
    }
};