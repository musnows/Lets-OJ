//https://leetcode.cn/problems/compress-string-lcci/
class Solution {
public:
    string compressString(string S) {
        if ((int)S.length() == 0) return S; // 空串处理
        string ans = "";
        int cnt = 1;
        char ch = S[0];
        for (int i = 1; i < (int)S.length(); ++i){
            if (ch == S[i]) cnt++;
            else{
                ans += ch + to_string(cnt); // 注意 cnt 要转为字符串
                ch = S[i];
                cnt = 1;
            }
        }
        ans += ch + to_string(cnt);
        return ans.length() >= S.length() ? S : ans;
    }
};

