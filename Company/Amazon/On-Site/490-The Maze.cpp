class Solution {
public:
    vector<int> des;
    bool dfs(int curi, int curj, vector<vector<int>> &maze, vector<vector<bool>> visited){
        if(visited[curi][curj]){
            return false;
        }   
        if(curi == des[0] && curj == des[1]){
            return true;
        }
        visited[curi][curj] = true;
        vector<int> x = {0,0,1,-1};
        vector<int> y = {1,-1,0,0};
        
        for(int i=0;i<4;i++){
            int nexti = curi + x[i];
            int nextj = curj + y[i];
            
            while(nexti>=0 && nextj>=0 && nexti<maze.size() && nextj<maze[0].size() && maze[nexti][nextj]==0){
                nexti+=x[i];
                nextj+=y[i];
            }
            
            nexti-=x[i];
            nextj-=y[i];
            
            if(dfs(nexti, nextj, maze, visited)){
                return true;
            }
        }
        return false;
        
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        des = destination;
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        return dfs(start[0], start[1], maze, visited);
    }
};