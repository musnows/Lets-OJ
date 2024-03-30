class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        int maxLength = -1;
        int curLength = 0;
        int left = 0,right = 0;
        unordered_set<char> sets;
        for(right = 0;right<s.size();right++)
        {
            // 找不到插入
            if(sets.count(s[right]) == 0){
                sets.insert(s[right]);
                curLength++;
                maxLength = max(maxLength,curLength);
                continue;
            }
            // 找到了，左侧缩限到上一个s[right]的位置
            while(s[left] != s[right])
            {
                // 每一次缩限都需要把字符从set删除
                sets.erase(s[left]);
                left++;
            }
            // 走到了上一个s[right]，需要再走一次
            left++;
            curLength = right-left+1;
            // 这里不需要修改sets，把原有的s[right]当作新插入的
        }

        return maxLength;
    }
};