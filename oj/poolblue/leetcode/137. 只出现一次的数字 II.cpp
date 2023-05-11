//https://leetcode.cn/problems/single-number-ii/
//137. 只出现一次的数字 II 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    unordered_map<int, int> freq;//利用哈希映射
        for (int num: nums) {
            ++freq[num];
        }
        int ans = 0;
        for (auto [num, occ]: freq) {
            if (occ == 1) {//找出仅一次出现的元素
                ans = num;
                break;
            }
        }
        return ans;

    }

