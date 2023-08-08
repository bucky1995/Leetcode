class Solution {
public:
    int countNeighbor(int r, int c, vector<vector<int>> board){
        int res = 0;
        vector<int> x = {0,0,1,-1,1,-1,1,-1};
        vector<int> y = {1,-1,0,0,1,-1,-1,1};

        for(int i=0;i<8;i++){
            int next_i = r+x[i];
            int next_j = c+y[i];

            if(next_i<0 || next_j<0 || next_i>=board.size() || next_j>=board[0].size()){
                continue;
            }
            if(board[next_i][next_j]==1 || board[next_i][next_j]==3)
                res++;
        }
        return res;

    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int live_n = countNeighbor(i,j,board);
                if((live_n<2 || live_n>3) && (board[i][j] == 1)){
                    board[i][j] = 3;
                }else if(board[i][j] == 0 && live_n==3){
                    board[i][j] = 4;
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]>1){
                    board[i][j]-=3;
                }
            }
        }
    }
};