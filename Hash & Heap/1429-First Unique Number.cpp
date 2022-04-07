class FirstUnique {
public:
    unordered_map<int,int> seen;
    queue<int> values;
    void insert_num(int num){
        seen[num] ++;
        values.push(num);
    }
    FirstUnique(vector<int>& nums) {
        for(int num : nums){
            insert_num(num);
        }
    }
    
    int showFirstUnique() {
        while(!values.empty() && seen[values.front()] >1){
            values.pop();
        }
        return values.empty() ? -1:values.front();
    }
    
    void add(int value) {
        insert_num(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */