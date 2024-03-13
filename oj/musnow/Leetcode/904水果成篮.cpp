class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_set<int> fruitsSet;
        int fruitsCount = 0; // 种类数量
        int curCount = 0; // 当前水果计数
        int retCount = -1;

        int left = 0,right = 0;
        while(right < fruits.size())
        {
            // 水果不在里面，且还没有2个
            if(fruitsCount < 2 && fruitsSet.count(fruits[right]) == 0){
                fruitsCount++; // 种类数量加一
                fruitsSet.insert(fruits[right]);
                curCount++; // 水果个数加一
                right++;
                retCount = max(curCount,retCount);
                // cout << right << " - " << fruits[right] << "\n";
            }
            // 水果在里面
            else if(fruitsCount <= 2 && fruitsSet.count(fruits[right]) != 0)
            {
                right++;
                curCount++;
                retCount = max(curCount,retCount);
            }
            // 水果不在里面，且已经有两个了
            else if(fruitsCount >= 2 && fruitsSet.count(fruits[right]) == 0)
            {
                retCount = max(curCount,retCount);
                fruitsSet.clear(); // 清空
                curCount = 0;
                fruitsCount = 0;
                // 找下一个和left当前不同的水果
                while(left < fruits.size() && fruits[left+1] == fruits[left]){
                    left++;
                }
                // 还需要再走一步，才是和刚刚不一样的水果
                left++;
                right = left; // 重新开始新一轮计数
            }
        }
        return retCount;
    }
};