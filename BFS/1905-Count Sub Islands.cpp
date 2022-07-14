class Solution {
public:
    bool mark(int m, int n, vector<vector<int>>& grid){
        queue<vector<int>> buffer;
        vector<int> x = {1,-1,0,0};
        vector<int> y = {0,0,1,-1};
        
        buffer.push({m,n});
        grid[m][n] = 0;
        bool count = true;
        while(!buffer.empty()){
            vector<int> point = buffer.front();
            buffer.pop();
            for(int i=0;i<4;i++){
                int row = point.front()+x[i];
                int col = point.back()+y[i];
                
                if(col<0||row<0||row>=grid.size()||col>=grid.front().size()){
                    continue;
                }
                if(grid[row][col] == 2){
                    grid[row][col] = 0;
                    buffer.push({row,col});
                }
                if(count && grid[row][col] == 1){
                    count = false;
                }
            }
        }
        return count;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[0].size();j++){
                if(grid1[i][j] == 1 && grid2[i][j] == 1){
                    grid2[i][j] = 2;
                }
            }
        }
        int res = 0;
        
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[0].size();j++){
                if(grid2[i][j] == 2){
                    if(mark(i,j,grid2)){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};