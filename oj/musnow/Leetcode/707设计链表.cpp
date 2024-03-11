struct Node
{
    int _val;
    Node* _next;
    Node(int v = 0):_val(v),_next(nullptr){}
};

class MyLinkedList {
    Node* _phead;
    size_t _size;
public:
    MyLinkedList() {
        _phead = new Node;
        _size = 0;
    }
    
    ~MyLinkedList() {
        Node* cur = _phead;
        while(cur!=nullptr)
        {
            Node* prev = cur;
            cur = cur->_next;
            delete prev;
        }
    }

    int get(int index) {
        if(index >= _size){
            return -1;
        }
        Node* cur = _phead->_next;
        while(index--)
        {
            cur = cur->_next;
        }
        return cur->_val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->_next = _phead->_next;
        _phead->_next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        size_t count = _size;
        Node* cur = _phead;
        while(count --)
        {
            cur = cur->_next;
        }
        // 结束的时候cur是最后一个节点
        Node* newNode = new Node(val);
        cur->_next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > _size){
            return ;
        }
        if(index == _size){
            return addAtTail(val);
        }
        // 走到节点之前的那一个
        Node* cur = _phead;
        while(index--)
        {
            cur = cur->_next;
        }
        Node* newNode = new Node(val);
        cout << _size<< endl;
        newNode->_next = cur->_next;
        cur->_next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= _size){
            return ;
        }
        // 走到节点之前的那一个
        Node* cur = _phead;
        while(index--)
        {
            cur = cur->_next;
        }
        // 删除
        Node* removeNode = cur->_next;
        cur->_next = cur->_next->_next;
        delete removeNode;
        _size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// https://leetcode.cn/problems/design-linked-list/description/