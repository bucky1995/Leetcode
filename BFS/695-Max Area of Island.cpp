class Solution {
public:
    int mark(int m, int n, vector<vector<int>>& grid){
        vector<int> x = {1,-1,0,0};
        vector<int> y = {0,0,1,-1};
        
        queue<vector<int>> buffer;
        
        buffer.push({m,n});
        grid[m][n] = 0;
        int area = 1;
        while(!buffer.empty()){
            vector<int> point = buffer.front();
            buffer.pop();
            for(int i=0; i<4;i++){
                int row = point.front() +x[i];
                int col = point.back() +y[i];
                
                if(row<0||col<0||row>=grid.size()||col>=grid[0].size()){
                    continue;
                }
                if(grid[row][col] == 1){
                    area++;
                    grid[row][col] =0;
                    buffer.push({row,col});
                }
            }
        }
        return area;
            
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_island = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    max_island = max(max_island, mark(i,j,grid));
                }
            }
        }
        
        return max_island;
    }
};