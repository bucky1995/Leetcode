class Solution {
public:
    vector<bool> path;
    vector<bool> visited;
    bool cycle;
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> res = vector<vector<int>>(numCourses, vector<int>{});
        
        for(vector<int> pair: prerequisites){
            int course = pair[0];
            int pre_course = pair[1];
            
            res[pre_course].push_back(course);
        }
        return res;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        
        path = vector<bool>(numCourses, false);
        visited = vector<bool>(numCourses, false);
        cycle = false;
        
        for(int i=0;i<numCourses;i++){
            travel(i, graph);
        }
        
        return !cycle;
    }
    
    void travel(int start, vector<vector<int>> &graph){
        if(path[start]){
            cycle = true;
            return;
        }
        
        if(visited[start] || cycle){
            return;
        }
        
        visited[start] = true;
        path[start] = true;
        for(int next: graph[start]){
            travel(next,graph);
        }
        path[start] = false;
    }
};