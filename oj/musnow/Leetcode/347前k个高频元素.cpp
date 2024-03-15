class Solution {
public:
    // 给优先级对列传入的仿函数
    // pair的第二个int是出现频率，通过它来排序
    class MyCmp {
    public:
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) 
        {
            // 使用大于，优先级对列建立小堆（猜测优先级队列采用向下调整，需要将大的往下调）
            return lhs.second > rhs.second; 
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> retV;

        unordered_map<int,int> maps;
        for(auto&e:nums){
            maps[e]++;
        }
        // 注意初始化的时候，第一个参数是存放的元素类型，第二个参数是使用的底层容器，第三个参数是自定义比较函数
        // 因为我们需要传入比较函数，所以也需要传入第二个容器参数，优先级对列默认使用的是vector
        priority_queue<pair<int,int>,vector<pair<int,int>>,MyCmp> que;
        // 遍历map，将pair传入，保证pair中只有k个元素，如果超过了，就将堆顶删除
        int count = 0;

        for(auto it = maps.begin();it != maps.end();it++)
        {
            que.push(*it);
            count++;
            if(count > k)
            {
                // 因为采用的是小堆，所以删除的元素是频率最小的那个
                // 这样能保证优先级队列中是前k个高频的
                que.pop();
                count--;
            }
        }
        // 此时优先级队列中就是前k个更大的元素
        while(count --)
        {
            retV.push_back(que.top().first);
            que.pop();
        }
        return retV;
    }
};

// https://leetcode.cn/problems/top-k-frequent-elements/description/