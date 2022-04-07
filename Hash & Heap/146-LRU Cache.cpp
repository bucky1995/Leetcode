class LRUCache {
public:
    
    class node{
    public:
        int val;
        int key;
        node* next;
        node* pre;
        
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    node* head;
    node* tail;
    
    int capacity;
    unordered_map<int,node*> hash;
    
    void del_node(node* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        hash.erase(node->key);
    }
    
    void put_to_end(node* node){
        tail->pre->next = node;
        node->pre = tail->pre;
        node->next = tail;
        tail->pre = node;
        hash[node->key] = node;
    }
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        int res = -1;
        if(hash.find(key)!= hash.end()){
            node* n = hash[key];
            res = n->val;
            del_node(n);
            put_to_end(n);
        }
        return res;
    }
    
    void put(int key, int value) {
        node *n = new node(key, value);


        if (hash.find(key) != hash.end()) {
            del_node(hash[key]);
        }
        if (hash.size() >= capacity) {
            del_node(head->next);
        }
        put_to_end(n);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */