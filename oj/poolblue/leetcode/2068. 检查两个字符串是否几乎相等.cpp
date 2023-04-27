//https://leetcode.cn/problems/check-whether-two-strings-are-almost-equivalent/
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> freq(26);//建立映射表
        auto n = word1.size();
        for (size_t i = 0; i < n; ++i) //进行频数计数
        {
            freq[word1[i]-'a']++;
            freq[word2[i]-'a']--;
        }
        for (const auto& n : freq) {
            if (n > 3 || n < -3) { //如果超过3次就返回false
                return false;
            }
        }
        return true;
    }
};
// class Solution {
// public:
//     bool checkAlmostEquivalent(string word1, string word2) {
//         unordered_map<char, int> freq;   // 频数差哈希表
//         for (auto ch: word1){
//             ++freq[ch];
//         }
//         for (auto ch: word2){
//             --freq[ch];
//         }
//         // 判断每个字符频数差是否均小于等于 3
//  return all_of(freq.cbegin(), freq.cend(), [](auto&& x) { return abs(x.second) <= 3; };
//     }
// };

 
