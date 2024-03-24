class FreqStack {
    unordered_map<int,stack<int>> stMap; // 每个频率都有一个栈
    unordered_map<int,int> countMap; // 频率计数
    int maxFreq = 0; // 最高频率
public:
    FreqStack() {}
    
    void push(int val) {
        // 将某个数字的频率加一
        countMap[val]++;
        stMap[countMap[val]].push(val);
        maxFreq = max(maxFreq,countMap[val]);
    }
    
    int pop() {
        // 从最高频率的栈中pop一个元素即可
        int val = stMap[maxFreq].top();
        stMap[maxFreq].pop();
        // 频率减一
        countMap[val]--;
        // 如果最大频率栈没有内容，则减一
        if(stMap[maxFreq].empty()){
            maxFreq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

// https://leetcode.cn/problems/maximum-frequency-stack/description/