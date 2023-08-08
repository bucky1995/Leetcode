class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, unordered_set<char>> map;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] != '.'){
                    char c = board[i][j];
                    string ver = to_string(i)+"hor";
                    string hor = to_string(j)+"ver";
                    int box_i = i/3;
                    int box_j = j/3;
                    string box = to_string(box_i) + "-" + to_string(box_j);
                    if(map[ver].count(c)!=0 || map[hor].count(c)!=0 || map[box].count(c)!=0){
                        return false;
                    }
                    map[ver].insert(c);
                    map[hor].insert(c);
                    map[box].insert(c);
                }
            }
        }
        return true;
    }
};