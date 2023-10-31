//https://leetcode.cn/problems/substrings-of-size-three-with-distinct-characters/solutions/802365/chang-du-wei-san-qie-ge-zi-fu-bu-tong-de-pr6h/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n - 2; ++i){
            if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]){
                ++res;
            }
        }
        return res;
    }
};

 
