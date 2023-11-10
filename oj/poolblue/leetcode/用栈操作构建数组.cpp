//https://leetcode.cn/problems/build-an-array-with-stack-operations/solutions/1890865/yong-zhan-cao-zuo-gou-jian-shu-zu-by-lee-omde/
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int prev = 0;
        for (int number : target) {
            for (int i = 0; i < number - prev - 1; i++) {
                res.emplace_back("Push");
                res.emplace_back("Pop");
            }
            res.emplace_back("Push");
            prev = number;
        }
        return res;
    }
};


