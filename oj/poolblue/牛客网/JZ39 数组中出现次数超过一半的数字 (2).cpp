class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int cond = -1;
        int cnt = 0;
        for (int i=0; i<numbers.size(); ++i) {
            if (cnt == 0) {
                cond = numbers[i];
                ++cnt;
            }
            else {
                if (cond == numbers[i]) ++cnt;
                else --cnt;
            }

        }
        cnt = 0;
        for (const int k :numbers) {
            if (cond == k) ++cnt;
        }
        if (cnt > numbers.size() / 2) return cond;
        return 0;
    }
};

