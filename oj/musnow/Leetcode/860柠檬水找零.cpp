class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // 剩余零钱初始化
        unordered_map<int, int> momenyMap;
        for (auto i : bills) {
            // 先计入获得的零钱
            momenyMap[i]++;
            i -= 5;
            // 原本是10元
            if (i == 5) {
                // 给她找5元
                momenyMap[5]--;
                // 没有零钱了，不行
                if (momenyMap[5] < 0) {
                    return false;
                }
            }
            // 原本是20元
            else if (i == 15) {
                // 先用10元的零钱，因为10元的零钱只有这时候可以用
                if (momenyMap[10] > 0 && momenyMap[5] > 0) {
                    momenyMap[5]--;
                    momenyMap[10]--;
                    continue;
                }
                // 如果没有十元的零钱，就用3个5元的零钱
                // 不够用，返回false
                if (momenyMap[5] < 3) {
                    return false;
                }
                // 扣掉零钱
                momenyMap[5] -= 3;
                continue;
            }
        }
        return true;
    }
};