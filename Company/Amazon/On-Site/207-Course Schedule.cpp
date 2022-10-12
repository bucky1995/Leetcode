class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> courses(numCourses, 0);
        unordered_map<int, unordered_set<int>> g;
        for(vector<int> c : prerequisites){
            int a = c[0];
            int b = c[1];
            courses[b]++;
            g[a].insert(b);
        }
        
        queue<int> buffer;
        for(int i=0;i<numCourses;i++){
            if(courses[i] == 0){
                buffer.push(i);
            }
        }
        int count = 0;
        while(!buffer.empty()){
            int c = buffer.front();
            buffer.pop();
            count++;
            for(int b : g[c]){
                courses[b]--;
                if(courses[b] == 0){
                    buffer.push(b);
                }
            }
        }
        
        return count == numCourses;
    }
};