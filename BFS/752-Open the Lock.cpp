class Solution {
public:
    unordered_set<string> hash;
    unordered_set<string> visited;
    bool possible(string next){
        if(hash.find(next) != hash.end())    return false;
        return true;
    }
    string turn_up(string cur, int digit){
        if(cur[digit] == '9'){
            cur[digit] = '0';
        }else{
            cur[digit]++;
        }
        return cur;
    }
    string turn_down(string cur, int digit){
        if(cur[digit] == '0'){
            cur[digit] = '9';
        }else{
            cur[digit]--;
        }
        return cur;
    }
    void generate(queue<string> &buffer, string cur, string target){
        
        string next_up;
        string next_down;
        for(int i=0;i<cur.size();i++){
            string next_up = turn_up(cur, i);
            string next_down = turn_down(cur, i);
            if(possible(next_up))   buffer.push(next_up);
            if(possible(next_down)) buffer.push(next_down);
        }
    }
    int openLock(vector<string>& deadends, string target) {
        hash.insert(deadends.begin(),deadends.end());
        int step = 0;
        
        queue<string> buffer;
        buffer.push("0000");
        if(hash.find("0000") != hash.end()){
            return -1;
        }
        while(!buffer.empty()){
            int n = buffer.size();
            for(int i=0;i<n;i++){
                string cur = buffer.front();
                buffer.pop();
                if(cur == target) return step;
                if(hash.find(cur) != hash.end())    continue;
                hash.insert(cur);
                generate(buffer, cur, target);
            }
            step++;
        }
        return -1;
    }
};