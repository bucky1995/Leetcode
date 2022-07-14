class Solution {
public:
    int mark(int m, int n, vector<vector<int>>& grid){
        vector<int> x = {1,-1,0,0};
        vector<int> y = {0,0,1,-1};
        
        queue<vector<int>> buffer;
        int moves = 1;
        buffer.push({m,n});
        grid[m][n] = 0;
        while(!buffer.empty()){
            vector<int> point = buffer.front();
            buffer.pop();
            for(int i=0;i<4;i++){
                int row = point[0]+x[i];
                int col = point[1]+y[i];
                if(row<0||col<0||row>=grid.size()||col>=grid[0].size()){
                    continue;
                }
                if(grid[row][col] == 1){
                    moves++;
                    buffer.push({row,col});
                    grid[row][col] = 0;
                }
            }
        }
        return moves;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            if(grid[i].front() == 1){
                mark(i,0,grid);
            }
            if(grid[i].back() == 1){
                mark(i,grid[0].size()-1,grid);
            } 
        }
        
        for(int i=0;i<grid[0].size();i++){
            if(grid.front()[i] == 1){
                mark(0,i,grid);
            }
            if(grid.back()[i] == 1){
                mark(grid.size()-1, i, grid);
            }
        }
        
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    res+=mark(i,j,grid);
                }
            }
        }
        return res;
    }
};