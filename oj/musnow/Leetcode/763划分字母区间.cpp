class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 统计每个字符最远出现的下标位置
        // unordered_map<char, int> indexMap;
        int indexMap[27] = {0};
        for (int i = 0; i < s.size(); i++) {
            indexMap[s[i]-'a'] = i;
        }
        // 遍历下标数组，如果当前数组的元素值和下标值相同，则找到了一个切割点
        vector<int> retV;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            // 每一次都是在start,end范围内，找已经出现过的字符的最远出现位置
            // 如果最终i等于end了，说明当前字符是之前出现过的字符最后出现过的一个位置
            // 在当前字符之后，是不会有其他已经出现过的字符的，不然这里的max就没有意义了
            end = max(end, indexMap[s[i]-'a']);
            if (i == end) {
                retV.push_back(i - start + 1); // 插入长度
                start = i + 1;
            }
        }
        return retV;
    }
};
