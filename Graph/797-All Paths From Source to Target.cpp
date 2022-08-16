class Solution {
public:
    vector<vector<int>> res;
    vector<int> visited;
    void travel(vector<int> path, vector<vector<int>>& graph){
        int currentNode = path.back();
        if(currentNode == graph.size()-1){
            res.push_back(path);
            return;
        }
        
        vector<int> next_nodes = graph[currentNode];
        for(int node : next_nodes){
            if(visited[node]){
                continue;
            }
            visited[node] = 1;
            path.push_back(node);
            travel(path, graph);
            visited[node] = 0;
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        visited = vector<int>(graph.size(), 0);
        visited[0] = 1;
        travel(vector<int>{0}, graph);
        return res;
    }
};