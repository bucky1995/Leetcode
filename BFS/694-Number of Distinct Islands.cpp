class Solution_dfs {
public:
    unordered_set<string> hash;
    vector<int> dir_set;
    void mark(int m, int n, vector<vector<int>>& grid, string &path, int dir){
        if(m<0||n<0||m>=grid.size()||n>=grid[0].size()||grid[m][n] == 0) return;
        grid[m][n] = 0;
        path.push_back(dir_set[dir]);
        queue<vector<int>> buffer;
        vector<int> x = {-1,0,1,0};
        vector<int> y = {0,1,0,-1};
        
        for(int i=0;i<4;i++){
            mark(m+x[i], n+y[i], grid, path, i);
        }
        path.push_back(dir_set[dir+4]);
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        int res = 0;
        dir_set.push_back('1');
        dir_set.push_back('2');
        dir_set.push_back('3');
        dir_set.push_back('4');
        dir_set.push_back('5');
        dir_set.push_back('6');
        dir_set.push_back('7');
        dir_set.push_back('8');
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    string path = "";
                    mark(i,j,grid, path, 0);
                    hash.insert(path);
                }
            }
        }
        return hash.size();
    }
};