class Solution {
public:
    int countDigitOne(int n) {
        int count = 0; // 结果
        // 不大于10的时候只会有一个
        if (n < 10 && n > 0) {
            return 1;
        }
        // 个位数 dights = 10^0 = 1
        long dights = 1;
        // high/cur/low 初始化为个位时的取值
        long high = n / 10; // 除去个位的其他值
        long cur = n % 10;  // 当前位是个位
        long low = 0;       // 个位没有low

        // high和cur同时为0代表遍历结束
        while (high != 0 || cur != 0) {
            if (cur == 0) {
                count += high * dights;
            } else if (cur == 1) {
                count += high * dights + low + 1;
            } else if (cur > 1) {
                count += (high + 1) * dights;
            }
            // 倍增，dights = 10^i
            dights *= 10;
            // 移动到下一位
            // 当cur为十位的时候，high是n/100
            // 当cur为百位的时候，high是n/1000
            high = n / (dights * 10);
            // 当cur为十位的时候，cur是(n/10)%10计算出来的
            // 当cur为百位的时候，cur是(n/100)%10计算出来的
            cur = (n / dights) % 10;
            // 当cur为十位的时候，low是%10计算出来的
            // 当cur为百位的时候，low是%100计算出来的
            low = n % dights;
        }
        return count;
    }
};