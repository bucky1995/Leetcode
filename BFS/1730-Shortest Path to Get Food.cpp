#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool valid_point(int i,int j, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0||j<0||i>=m||j>=n||grid[i][j] == 'X'){
            return false;
        }
        return true;
    }
    void get_next_steps(vector<vector<char>>& grid, vector<vector<int>>& buffer,
                        int cur_m, int cur_n){
        vector<vector<int>> next_steps;
        int i;
        vector<int> x = {1,-1,0,0};
        vector<int> y = {0,0,-1,1};
        
        for(int i=0;i<4;i++){
            if(valid_point(cur_m + x[i], cur_n + y[i],grid)){
                buffer.push_back({cur_m + x[i], cur_n + y[i]});
                grid[cur_m + x[i]][cur_n + y[i]] = 'X';
            }
        }
    }
    
    
    int getFood(vector<vector<char>>& grid) {
        int start_a,start_b;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '*'){
                    start_a = i;
                    start_b = j;
                    
                }
            }
        }
        
        vector<vector<int>> buffer;
        buffer.push_back({start_a,start_b});
        
        vector<vector<int>> visited (grid.size(),vector<int>(grid[0].size(), 0));
        visited[start_a][start_b] = 1;
        int steps = 0;
        
        while(!buffer.empty()){
            steps++;
            
            int size = buffer.size();
            while(size!=0){
                int cur_m = buffer.front().front();
                int cur_n = buffer.front().back();
                // if(grid[cur_m][cur_n] == '#'){
                //     return steps;
                // }
                buffer.erase(buffer.begin());
                
                //get_next_steps(grid,visited,buffer,cur_m,cur_n);
                vector<vector<int>> next_steps;
                int i;
                vector<int> x = {1,-1,0,0};
                vector<int> y = {0,0,-1,1};
                for(int i=0;i<4;i++){
                    if(valid_point(cur_m + x[i], cur_n + y[i],grid)){
                        if(grid[cur_m + x[i]][cur_n + y[i]] == '#')
                        {
                            return steps;
                        }
                        buffer.push_back({cur_m + x[i], cur_n + y[i]});
                        grid[cur_m + x[i]][cur_n + y[i]] = 'X';
                    }
                }
                size--;
            }
        }
        return -1;
    }
};