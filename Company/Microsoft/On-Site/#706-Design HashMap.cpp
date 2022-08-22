class MyHashMap {
public:
    vector<vector<vector<int>>> buffer;
    int hash(int key){
        return key%1000;
    }
    
    MyHashMap() {
        buffer.resize(1000);
    }
    
    void put(int key, int value) {
        int key_hash = hash(key);
        vector<vector<int>> value_set = buffer[key_hash];
        for(int i=0;i<value_set.size();i++){
            if(key == value_set[i][0]){
                value_set[i][1] = value;
                buffer[key_hash].clear();
                buffer[key_hash] = value_set;
                return;
            }
        }
        buffer[key_hash].push_back({key, value});
    }
    
    int get(int key) {
        int key_hash = hash(key);
        for(vector<int> key_value : buffer[key_hash]){
            if(key_value[0] == key)
                return key_value[1];
        }
        return -1;
    }
    
    void remove(int key) {
        int key_hash = hash(key);
        for(int i=0;i<buffer[key_hash].size();i++){
            vector<int> key_value = buffer[key_hash][i];
            if(key_value[0] == key){
                buffer[key_hash].erase(buffer[key_hash].begin()+i);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */