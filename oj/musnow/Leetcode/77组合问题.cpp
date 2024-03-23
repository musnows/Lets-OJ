class Solution {
    
    // curV不需要加引用，因为是回溯算法
    void _combine(int n,int k,int start,vector<int> curV,vector<vector<int>>& retV)
    {
        // 数量足够，插入结果集
        if(curV.size() == k){
            retV.push_back(curV);
            return;
        }
        // 遍历进行回溯
        // for(int i = start;i<=n;i++) // 正常遍历

        // 剪枝操作，如果下一层剩下的都不足k个了，那就不需要继续了
        // 比如这一层是1 2 3 4，选择了3后只剩4，但k=4，此时完全不够长度，这次遍历是没有意义的
        // 计算n减去k还需要多少个，就能削减掉下一层不够用的情况
        // https://www.programmercarl.com/0077.%E7%BB%84%E5%90%88.html#%E6%80%9D%E8%B7%AF
        for(int i = start;i<=n -(k-curV.size()-1);i++)
        {
            // 将当前值插入，然后递归进行下一次处理
            curV.push_back(i);
            // 这里应该从当前遍历值的下一个开始继续操作
            _combine(n,k,i+1,curV,retV);
            curV.pop_back(); // 回溯，撤销这一次操作
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> retV;
        // 注意，题目给的范围是1到n
        _combine(n,k,1,vector<int>(),retV);
        return retV;
    }
};

// [77. 组合](https://leetcode.cn/problems/combinations/)