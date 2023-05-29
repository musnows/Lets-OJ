https://leetcode.cn/problems/lru-cache-lcci/
class LRUCache {
struct DLinkedNode{
  int key;
  int value;
  DLinkedNode *prev;
  DLinkedNode *next;
  DLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}//无参构造函数，用于定位赋值
  DLinkedNode(int _key,int _value)
  :key(_key),value(_value),prev(nullptr),next(nullptr){}//有参构造函数，用于数据插入
};
private:
   unordered_map<int,DLinkedNode*>cache;
   DLinkedNode *head;
   DLinkedNode *tail;
   int size;
   int capacity;
public:
    LRUCache(int _capacity):
    capacity(_capacity),size(0)
     {
      // 使用伪头部和伪尾部节点
       head=new DLinkedNode();
       tail=new DLinkedNode();
       //双向链表
       head->next=tail;
       tail->prev=head;

    }
    
    int get(int key) {
       if(!cache.count(key))
         return -1;
        //如果key在，通过哈希表进行定位
        DLinkedNode *node =cache[key];
        //将节点移到链表头部，为最近使用
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
       if(!cache.count(key))
       {
           //如果key不存在，创建新节点
           DLinkedNode *node=new DLinkedNode(key,value);
           //添加进哈希表
           cache[key]=node;
           // 将节点添加到链表头部，
           addToHead(node);
           ++size;
           if(size>capacity)//如果超出容量大小，删除尾部链表节点
           {   //删除链表尾部，并记录节点
               DLinkedNode * removed = removedToTail();
               //删除哈希表key节点
               cache.erase(removed->key);
               delete removed;
               size--;
           }
       }
       else //如果key存在，通过哈希表进行定位，修改value，然后移到头部
       {
          DLinkedNode *node =cache[key];
          node->value=value;
          moveToHead(node);
       }

    }
    //添加到链表头部，靠近头部的则为最近使用
      void addToHead(DLinkedNode* node)
      {
         node->prev=head;
         node->next= head->next;
         head->next->prev=node;
         head->next=node;
         
      }
    //删除节点
      void removeNode(DLinkedNode* node)
      {
        node->prev->next=node->next;
        node->next->prev=node->prev;
        
      }
    //删除头部节点
      void moveToHead(DLinkedNode* node)
      {
        //先删除原本节点位置，再移到头部
        removeNode(node);
        addToHead(node);
      }
    //删除尾部节点
      DLinkedNode* removedToTail()//返回删除节点，用于哈希表定位删除
      {
          DLinkedNode * node=tail->prev;
          removeNode(node);
          return node;
      }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
