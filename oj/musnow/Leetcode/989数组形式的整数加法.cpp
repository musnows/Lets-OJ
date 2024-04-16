class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> retV;
        int i = num.size() - 1;
        int carry = 0; // 进位
        // 有一个不为0就需要继续加
        while (i >= 0 || k != 0) {
            // 可能有一个已经结束了，需要判断
            int a = i >= 0 ? num[i] : 0;
            int b = k != 0 ? k % 10 : 0;

            int sum = a + b + carry;
            int cur = sum % 10;          // 当前位
            carry = (sum >= 10) ? 1 : 0; // 如果超过10了需要进位
            // 插入数组
            retV.push_back(cur);
            // 走下一位去
            i--;
            k /= 10;
        }
        // 还有进位，需要再插入一个
        if (carry != 0) {
            retV.push_back(1);
        }
        // 注意，我们插入是尾插（vector头插效率很低），需要逆置
        reverse(retV.begin(), retV.end());
        return retV;
    }
};