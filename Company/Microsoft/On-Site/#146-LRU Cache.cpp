class LRUCache {
public:
    struct Node {
        int val;
        int key;
        Node* next;
        Node* pre;
        Node(int k, int v){
            val = v;
            key = k;
            next = NULL;
            pre = NULL;
        }
    };
    int max;
    int cur;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> map;
    LRUCache(int capacity) {
        cur = 0;
        max = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->pre = head;
    }
    void del_node(Node* p){
        p->pre->next = p->next;
        p->next->pre = p->pre;
        map.erase(p->key);
    }
    void put_front(Node* p){
        head->next->pre = p;
        p->pre = head;
        p->next = head->next;
        head->next = p;        
        map[p->key] = p;
    }
    
    int get(int key) {
        if(map.count(key) == 0) return -1;
        Node* p = map[key];
        del_node(p);
        put_front(p);
        return p->val;
    }
    
    void put(int key, int value) {
        Node* n = new Node(key, value);
        if(map.count(key) !=0){
            del_node(map[key]);
        }
        if(map.size() >= max){
            del_node(tail->pre);
        }
        put_front(n);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */