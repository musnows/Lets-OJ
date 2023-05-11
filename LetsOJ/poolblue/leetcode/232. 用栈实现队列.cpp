//https://leetcode.cn/problems/implement-queue-using-stacks/
class MyQueue {
public:
    MyQueue() { }//构造函数可写可不写
    
    void push(int x) {
      s1.push(x);
    }
    
    void inToOut()//使输入栈的数据转移到输出栈
    {
        while(!s1.empty())
      {
          int x=s1.top();
          s1.pop();
          s2.push(x);
      }
    }
    int pop() {
        
       if(s2.empty())//如果输出栈为空，转移数据
       {
           inToOut();
       }
      int x=s2.top();
      s2.pop();
      return x;
    }
    
    int peek() {
       if(s2.empty())//如果输出栈为空，转移数据
       {
           inToOut();
       }
       int x=s2.top();
       return x;
    }
    
    bool empty() {
       return s1.empty() &&s2.empty();
       
    }
private:
   stack<int> s1;//输入栈
   stack<int> s2;//输出栈
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
