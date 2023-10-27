//https://leetcode.cn/problems/kth-distinct-string-in-an-array/submissions/477801316/
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // 维护 arr 中每个字符串的频数
        unordered_map<string, int> freq;
        for (const string& s: arr){
            if (!freq.count(s)){
                freq[s] = 0;
            }
            ++freq[s];
        }
        // 遍历 arr 寻找第 k 个独一无二的字符串
        for (const string& s: arr){
            if (freq[s] == 1){
                --k;
                if (k == 0){
                    return s;
                }
            }
        }
        return "";
    }
};


