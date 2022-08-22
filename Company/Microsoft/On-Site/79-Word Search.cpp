class Solution {
public:
    vector<vector<int>> visited;
    vector<int> x = {0,0,1,-1};
    vector<int> y = {1,-1,0,0};
    int m;
    int n;
    bool deep_validate(vector<vector<char>>& board, string word, int next, int start_i, int start_j){
        if(next == word.size()-1){
            return true;
        }
        
        for(int a=0;a<4;a++){
            int next_x = start_i+x[a];
            int next_y = start_j+y[a];
            if(next_x<0 || next_x>=m || next_y<0 || next_y>=n || board[next_x][next_y]!= word[next+1]||visited[next_x][next_y]==1)
                continue;
            visited[next_x][next_y] = 1;
            if(deep_validate(board, word, next+1, next_x, next_y))
                return true;
            visited[next_x][next_y] = 0;
        }
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    visited = vector<vector<int>>(m, vector<int>(n, 0));
                    visited[i][j] = 1;
                    if(deep_validate(board, word, 0, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};