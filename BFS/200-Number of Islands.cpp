#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    void mark_island(vector<vector<int>>& visited, vector<vector<char>>& grid,
                    int p1, int p2){
        vector<vector<int>> buffer;
        buffer.push_back(vector<int> {p1,p2});
        while(!buffer.empty()){
            int m = buffer.front().front();
            int n = buffer.front().back();
            buffer.erase(buffer.begin());
            
            int i;
            //left
            i = n-1;
            if(i>=0&&grid[m][i] == '1' &&visited[m][i] != 1){
                visited[m][i] = 1;
                buffer.push_back({m,i});
            }
            // while(i>=0&&grid[m][i] == '1' &&visited[m][i] != 1){
            //     visited[m][i] = 1;
            //     buffer.push_back({m,i});
            //     i--;
            // }
            //right
            i = n+1;
            if(i<grid[0].size()&&grid[m][i] == '1'&&visited[m][i] != 1){
                visited[m][i] = 1;
                buffer.push_back({m,i});
            }
            // while(i<grid[0].size()&&grid[m][i] == '1'&&visited[m][i] != 1){
            //     visited[m][i] = 1;
            //     buffer.push_back({m,i});
            //     i++;
            // }
            //down
            i = m+1;
            if(i<grid.size()&&grid[i][n] == '1'&&visited[i][n] != 1){
                visited[i][n] = 1;
                buffer.push_back({i,n});
            }
            // while(i<grid.size()&&grid[i][n] == '1'&&visited[i][n] != 1){
            //     visited[i][n] = 1;
            //     buffer.push_back({i,n});
            //     i++;
            // }
            //up
            i = m-1;
            if(i>=0&&grid[i][n] == '1'&&visited[i][n] != 1){
                visited[i][n] = 1;
                buffer.push_back({i,n});
            }
            // while(i>=0&&grid[i][n] == '1'&&visited[i][n] != 1){
            //     visited[i][n] = 1;
            //     buffer.push_back({i,n});
            //     i--;
            // }
        }
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        vector<vector<int>> visited( grid.size(), 
                                    vector<int> (grid[0].size(), 0));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1' && visited[i][j] != 1){
                    count++;
                    visited[i][j] = 1;
                    mark_island(visited, grid,i,j);
                }
            }
        }
        return count;
    }
};