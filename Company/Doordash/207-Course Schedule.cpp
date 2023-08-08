class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> g;
        for(vector<int> pair : prerequisites){
            int a = pair[0];
            int b = pair[1];
            indegree[a]++;
            g[b].push_back(a);
        }

        queue<int> buffer;
        vector<int> res;
        for(int i=0;i<numCourses;i++){
            if(indegree.count(i)==0){
                buffer.push(i);
            }
        }
        int n = numCourses;
        while(!buffer.empty()){
            int c = buffer.front();
            buffer.pop();
            for(int next_c: g[c]){
                indegree[next_c]--;
                if(indegree[next_c] == 0){
                    buffer.push(next_c);
                }
            }
            n--;
        }
        return n == 0;
    }
};