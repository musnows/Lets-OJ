// https://leetcode.cn/problems/group-anagrams/?envType=study-plan-v2&envId=top-100-liked
// 同样是用哈希的思想，
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if(strs.size() <= 1){
            ret.push_back(strs);
            return ret;
        }

        // 将字符串进行排序，然后判断是否相等
        // 排序后的字符串作为key，字母异位词的排序后一定相同
        unordered_map<string,vector<string>> m;
        for(auto&s :strs)
        {
            string key = s;
            sort(key.begin(),key.end());
            m[key].push_back(s); // 将排序前的字符串作为value插入
        }
        // 复原成vector
        for(auto&v:m)
        {
            ret.push_back(v.second);
        }
        return ret;
    }
};