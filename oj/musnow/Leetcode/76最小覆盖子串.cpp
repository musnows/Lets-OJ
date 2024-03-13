// https://leetcode.cn/problems/minimum-window-substring/description/

class Solution {
public:
    // 判断当前map中是否已经包含目标map中需要的所有字符
    bool statusCheck(const unordered_map<char,int>& tMaps,unordered_map<char,int>& curMaps)
    {
        for(auto&e:tMaps){
            // 这里不能用不等于判断，因为curMaps中的计数器大于的时候也是符合条件的
            if(curMaps.count(e.first)!=0 && curMaps[e.first] < e.second){
                return false;
            }
            else if (curMaps.count(e.first)==0)
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }

        int left = 0,right = 0;
        int begin = -1, end = -1, len = INT32_MAX; // 最终用于返回结果的下标区间
        // 记录t中每个字符出现的次数
        unordered_map<char,int> tMaps;
        for(auto&e:t){
            tMaps[e]++;
        }
        // 当前出现的tmap中的字符的数量
        unordered_map<char,int> curMaps;
        while(right < s.size())
        {
            // 如果目标map里面有，则在当前map里面将数量加一
            if(tMaps.count(s[right]) !=0){
                curMaps[s[right]]++;
            }
            // 如果符合条件，则缩限到不能缩限为止
            while(statusCheck(tMaps,curMaps) && left <=right)
            {
                // 如果长度小于当前记录的长度，则更新
                if(right - left + 1 < len)
                {
                    len = right - left + 1;
                    begin = left;
                    end = right;
                }
                // 在目标map里面看是否有这个字符串，有则在当前map中将数量减一
                if(tMaps.count(s[left]) !=0){
                    curMaps[s[left]]--;
                }
                left++;
            }
            right++;
        }
        // 如果begin没有被更新，则说明不存在
        return begin == -1 ? "" : s.substr(begin,len);
    }
};