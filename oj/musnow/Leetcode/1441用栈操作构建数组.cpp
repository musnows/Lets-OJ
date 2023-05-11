class Solution {
public:
    #define IN "Push"
    #define OUT "Pop"
    vector<string> buildArray(vector<int>& target, int n) {
        int cur = 1;//当前模拟list中的数字
        vector<string> ret;
        ret.reserve(target.size());
        for(int i=0;i<target.size();i++)
        {
            while(cur != target[i])
            {
                cout << "while cur: " << cur << " target: " << target[i]<<endl;
                // 当前cur和target[i]不相同，肯定是cur小
                // 不断push和pop直到cur和target[i]相同
                ret.push_back(IN);
                ret.push_back(OUT);
                cur++;
            }
            // 相同，代表一个push操作
            if(target[i] == cur)
            {
                ret.push_back(IN);
                cur++;
            }
        }
        return ret;
    }
};

//https://leetcode.cn/problems/build-an-array-with-stack-operations/description/