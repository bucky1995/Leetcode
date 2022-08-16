class Solution {
public:
    vector<bool> visited;
    vector<bool> colored;
    bool bipartite;
    
    void dfs(int node, vector<vector<int>>& graph){
        if(!bipartite){
            return;
        }
        visited[node] = true;
        for(int next : graph[node]){
            if(!visited[next]){
                colored[next] = !colored[node];
                dfs(next, graph);
            }else{
                if(colored[next] == colored[node]){
                    bipartite = false;
                    return;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        bipartite = true;
        visited = vector<bool>(graph.size(), false);
        colored = vector<bool>(graph.size(), false);
        for(int i=0;i<graph.size();i++){
            if(!visited[i])
                dfs(i, graph);
        }
        return bipartite;
    }
};