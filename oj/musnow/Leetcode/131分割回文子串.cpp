class Solution {
    vector<vector<string>> retV; // 返回值数组
    vector<string> curV;         // 当前的回文子串

    void _partition(string s, int startIndex) {
        // 越界，说明上一层i已经是s.size()-1，此时分割线是在字符串末尾；
        // 已经是最后一个分割线了，说明找到了符合条件的切割（没找到是走不到这里来的）
        if (startIndex >= s.size()) {
            retV.push_back(curV);
            return;
        }
        // 遍历，将下标当作子串
        for (int i = startIndex; i < s.size(); i++) {
            // 如果是，将这里作为一个子串切割，递归到下一层找其他子串
            // 子串区间一直都是闭区间 [startIndex,i]
            // 此时i和i+1之间可以想象成有一个分割线
            if (isReverseString(s, startIndex, i)) {
	            // 插入当前选择的子串
                string temp = s.substr(startIndex, i - startIndex + 1);
                curV.push_back(temp);
                // 递归下一层
                // _partition(s, startIndex + 1); // 错误，i才是分割线位置
                _partition(s, i + 1);
                
                // 弹出当前选择的子串
                curV.pop_back(); // 回溯
            }
            // 如果不是，这一次的切割已经无效了，直接跳过
            else {
                // 注意不能break，因为后序可能还会有回文的情况
                // 比如ab和aba
                continue;
            }
        }
    }
    // 判断是否为回文子串，双指针法
    bool isReverseString(const string& str, int begin, int end) {
        for (int i = begin, j = end; i < j; i++, j--) {
            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        _partition(s, 0);
        return retV;
    }
};

// https://leetcode.cn/problems/palindrome-partitioning/