class MyStack {
    int size = 0;
    queue<int> que;
public:
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
        size++;
    }
    
    int pop() {
        // 把前面的数据全部移动到后面去
        int count = size;
        while(count-->1){
            int temp = que.front();
            que.pop();
            que.push(temp);
        }
        // 剩下的是需要删除的
        int ret = que.front();
        que.pop();
        size--;
        return ret;
    }
    
    int top() {
        // 这里不能复用函数了，因为位置移动后必须要删除才是对的，否则会乱
        // 把前面的数据全部移动到后面去
        int count = size;
        while(count-->1){
            int temp = que.front();
            que.pop();
            que.push(temp);
        }
        // 剩下的是top函数
        int ret = que.front();
        que.push(ret);
        que.pop(); // 需要把这个数字也移动到后面去
        return ret;
    }
    
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */