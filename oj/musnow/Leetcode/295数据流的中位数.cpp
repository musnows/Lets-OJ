class MedianFinder {
    // 注意优先级队列C++中默认的比较函数是less，存放的是大堆
    priority_queue<int> _queBig; // 大堆，存放小半边数据
    priority_queue<int, vector<int>, std::greater<int>>
        _queSm; // 小堆，存放大半边数据
public:
    MedianFinder() {}

    // 保证较大的一半数据更多
    // 奇数的时候较大的一半堆顶就是中位数
    // 偶数的时候，较小+较大堆顶/2就是中位数
    void addNum(int num) {
        if (_queBig.size() == _queSm.size()) {
            // 注意sm存放的是大的那一半
            // _queSm.push(num);
            // error！不能直接插入!
            // 先把num插入到big里面，再把big里面最大的那个数插入到sm里面！
            // 因为需要保证有序，如果直接插入，此时num的值可能比big里面的堆顶元素小！
            _queBig.push(num);
            _queSm.push(_queBig.top());
            _queBig.pop();
            return;
        }
        // 大的那一半数据更多
        // 注意sm存放的是大的那一半
        if (_queBig.size() < _queSm.size()) {
            // 如果当前数比大堆堆顶的更大，则需要放到大的那一半中
            if (num > _queSm.top()) {
                _queBig.push(_queSm.top());
                _queSm.pop();
                _queSm.push(num);
                return;
            }
            // 其他情况都往小的那一半里面插
            _queBig.push(num);
        }
        return;
    }

    double findMedian() {
        if (_queBig.size() == _queSm.size()) {
            return double((_queBig.top() + _queSm.top()) / 2.0);
        }
        // sm才是大的那一半
        return double(_queSm.top() * 1.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// https://leetcode.cn/problems/find-median-from-data-stream/description/