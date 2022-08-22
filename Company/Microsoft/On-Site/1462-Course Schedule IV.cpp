class Solution {
public:
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> helper;
        unordered_map<int, unordered_set<int>> preC; //c->c's pre
        
        vector<int> indegrees = vector<int>(numCourses, 0);
        for(vector<int> c: prerequisites){
            int ai = c.front();
            int bi = c.back();
            helper[ai].push_back(bi);
            indegrees[bi]++;
            preC[bi].insert(ai);
        }
        
        queue<int> buffer;
        
        for(int i=0;i<numCourses;i++){
            if(indegrees[i] == 0)
                buffer.push(i);
        }
        
        while(!buffer.empty()){
            int c = buffer.front();
            buffer.pop();
            
            vector<int> nextC = helper[c];
            
            for(int next : nextC){
                indegrees[next]--;
                if(indegrees[next] == 0)
                    buffer.push(next);
                for(int p : preC[c]){
                    preC[next].insert(p);
                }
            }
        }
        vector<bool> res;
        
        for(vector<int> q: queries){
            res.push_back(preC[q.back()].count(q.front()) != 0);
        }
        
        return res;
    }
};