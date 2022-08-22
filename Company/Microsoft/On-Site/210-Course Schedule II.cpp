class Solution {
public:
    unordered_map<int, unordered_set<int>> helper;
    vector<int> indegrees;
    unordered_set<int> taken;
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        indegrees = vector<int>(numCourses, 0);
        for(vector<int> c : prerequisites){
            int ai = c.front();
            int bi = c.back();
            helper[bi].insert(ai);
            indegrees[ai]++;
        }
        queue<int> buffer;
        for(int c = 0;c<numCourses;c++){
            if(indegrees[c] == 0)
                buffer.push(c);
        }
        int i=0;
        while(!buffer.empty()){
            int c = buffer.front();
            res.push_back(c);
            buffer.pop();
            
            unordered_set<int> nextC = helper[c];
            
            for(int next : nextC){
                indegrees[next]--;
                if(indegrees[next] == 0)
                    buffer.push(next);
            }
        }
        
        if(res.size() == numCourses)
            return res;
        return {};
    }
};