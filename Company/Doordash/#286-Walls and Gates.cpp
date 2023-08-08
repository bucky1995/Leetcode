class Solution {
public:
    int inf = 2147483647;
    void bfs(queue<vector<int>> buffer, vector<vector<int>>& rooms){
        vector<int> x = {0,0,1,-1};
        vector<int> y = {1,-1,0,0};
        vector<vector<int>> visited(rooms.size(), vector<int>(rooms[0].size(), 0));
        int steps = 0;
        while(buffer.size()!=0){
            vector<int> block = buffer.front();
            buffer.pop();
            int i = block[0];
            int j = block[1];
            
            for(int k = 0; k<4;k++){
                int next_i = i+x[k];
                int next_j = j+y[k];
                if(next_i<0 || next_j<0 || next_i>=rooms.size() || next_j>=rooms[0].size() || rooms[next_i][next_j]!=inf)
                    continue;
                rooms[next_i][next_j] = rooms[i][j]+1;
                buffer.push({next_i, next_j});
            }
        }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<vector<int>> buffer;
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[0].size();j++){
                if(rooms[i][j] == 0){
                    buffer.push({i,j});
                }
            }
        }
        bfs(buffer, rooms);
    }
};