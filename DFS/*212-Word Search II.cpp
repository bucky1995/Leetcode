class Solution {
public:
    bool DFS(vector<vector<char>>& board, string current_word, string target,
             int current_n, int current_m){
        if(current_n<0 || current_n>=board.size() || current_m<0 || current_m>=board[0].size()){
            return false;
        }
        
        current_word.push_back(board[current_n][current_m]);
        char c = board[current_n][current_m];
        board[current_n][current_m] = '*';
        
        if(current_word.back() != target[current_word.size()-1]){
            board[current_n][current_m] = c;
            return false;
        }
        
        if(target.compare(current_word) == 0){
            board[current_n][current_m] = c;
            return true;
        }
        
        vector<int> x = {0,0,1,-1};
        vector<int> y = {1,-1,0,0};
        
        bool found = false;
        
        for(int i=0;i<4;i++){
            if(DFS(board, current_word, target, current_n + x[i], current_m + y[i])){
                found = true;
            }
        }
        
        board[current_n][current_m] = c;

        return found;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        vector<vector<int>> visited (board.size(), vector<int> (board[0].size(), 0));
        unordered_map<char, vector<vector<int>>> map;

        for(int n=0;n<board.size();n++){
            for(int m = 0;m<board[0].size();m++) {
                if(map.find(board[n][m]) == map.end()){
                    map[board[n][m]] = {{n,m}};
                }else{\
                    map[board[n][m]].push_back({n,m});
                }
            }
        }
        for(int i=0;i<words.size();i++){
            string word = words[i];
            bool found = false;
            bool cont = false;
            
            for(int k = 0;k<word.size();k++){
                if(map.find(word[k]) == map.end()){
                    cont = true;
                    break;
                }
            }
            if(!cont){
                vector<vector<int>> position = map[word.front()];
                for(int j=0;j<position.size() && !found;j++){
                    if( DFS(board, "", word, position[j][0], position[j][1])){
                        res.push_back(word);
                        found = true;
                    }
                }
            }
        }

        return res;
    }
};