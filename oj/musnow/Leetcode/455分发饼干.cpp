class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int index = s.size() - 1; // 饼干最后一个
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index < 0) {
                break;
            }
            if (s[index] >= g[i]) {
                index--;
                count++;
            }
        }
        return count;
    }
};