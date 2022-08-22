class MyHashSet {
public:
    vector<vector<int>> buffer;
    MyHashSet() {
        buffer.resize(1000);
    }
    int hash(int key){
        return key%1000;
    }
    
    void add(int key) {
        int key_hash = hash(key);
        for(int i=0;i<buffer[key_hash].size();i++){
            if(buffer[key_hash][i] == key){
                return;
            }
        }
        buffer[key_hash].push_back(key);
    }
    
    void remove(int key) {
        int key_hash = hash(key);
        for(int i=0;i<buffer[key_hash].size();i++){
            if(buffer[key_hash][i] == key){
                buffer[key_hash].erase(buffer[key_hash].begin()+i);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int key_hash = hash(key);
        for(int i=0;i<buffer[key_hash].size();i++){
            if(buffer[key_hash][i] == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */