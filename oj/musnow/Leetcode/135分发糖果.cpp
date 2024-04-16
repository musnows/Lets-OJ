class Solution {
public:
    int candy(vector<int>& ratings) {
        // 先给所有人分一个糖果
        vector<int> candyArray(ratings.size(), 1);
        // 从左往右遍历，如果当前孩子比左边的孩子分数多，则让当前的孩子多分一个糖果
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candyArray[i] = candyArray[i - 1] + 1;
            }
        }
        // 从右往左遍历，如果当前孩子比右边孩子分数多，则让当前孩子多分一个糖果
        // 注意这里我们需要从倒数第二个孩子开始，此时它的下标是sz-2
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                // 因为前面已经操作过一次了，此时可能当前孩子的糖果已经比i+1多了，那么就需要判断
                // 不然右边孩子的糖果数量+1小于当前已有糖果时，直接赋值会导致左侧条件不满足。
                candyArray[i] = max(candyArray[i + 1] + 1, candyArray[i]);
            }
        }
        // 计算糖果数量
        int count = 0;
        for (auto& c : candyArray) {
            count += c;
        }
        return count;
    }
};