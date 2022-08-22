class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,int> indegrees;
        unordered_set<char> hash;
        unordered_map<char, unordered_set<char>> g;
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                indegrees[words[i][j]] = 0;
            }
        }
        
        for(int i=0;i<words.size()-1;i++){
            string a = words[i];
            string b = words[i+1];
            
            if(a.size() > b.size() && a.substr(0,b.size()) == b)
                return "";
            
            for(int j=0;j<min(a.size(),b.size());j++){
                if(a[j]!=b[j]){
                    if(g[a[j]].count(b[j])==0)
                        indegrees[b[j]]++;
                    g[a[j]].insert(b[j]);
                    break;
                }
            }
        }
        
        queue<char> buffer;
        
        for(pair<int,int> in : indegrees){
            if(in.second == 0)
                buffer.push(in.first);
        }
        string res;
        while(!buffer.empty()){
            char c = buffer.front();
            buffer.pop();
            
            res.push_back(c);
            
            unordered_set<char> nextC = g[c];
            
            for(char next : nextC){
                indegrees[next]--;
                if(indegrees[next] == 0)
                    buffer.push(next);
            }
        }
        
        if(res.size()!=indegrees.size())
            res = "";
        return res;
        
    }
};