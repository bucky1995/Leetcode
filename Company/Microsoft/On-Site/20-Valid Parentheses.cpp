class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 !=0)  return false;
        unordered_map<char, char> left;
        unordered_set<char> right;
        left['('] = ')';
        left['['] = ']';
        left['{'] = '}';
        
        queue<char> str;
        for(char c : s)
            str.push(c);
        
        vector<char> buffer;
        while(!str.empty()){
            char c = str.front();
            str.pop();
            
            if(left.count(c) !=0){
                buffer.push_back(c);
            }else{
                if(buffer.empty() || left[buffer.back()] != c)
                    return false;
                buffer.pop_back();
            }
        }
        return buffer.empty()? true : false;
    }
};