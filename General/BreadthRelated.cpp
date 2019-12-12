#include <iostream> 
#include <unordered_map> 
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    //this one is a sucker, also queue is much faster when pop front, like 75% faster than vector
    bool onBoard(int i,int j,vector<vector<char>>& board){
        int up=board.size()-1;
        int right=board[0].size()-1;
        if(i==0||j==0||i==up||j==right){
            return true;
        }else{
            return false;
        }
    }
    vector<pair<int,int>> getNeighber(int i,int j,vector<vector<char>>& board,vector<vector<int>> &mark){
        vector<pair<int,int>> res;
        if(j+1<board[i].size()){
            if(mark[i][j+1]==0&&board[i][j+1]=='O'){
                res.push_back({i,j+1});
            }
        }
        if(j-1>=0) {
            if(mark[i][j-1]==0&&board[i][j-1]=='O'){
                res.push_back({i,j-1});
            }
        }
        if(i-1>=0) {
            if(mark[i-1][j]==0&&board[i-1][j]=='O'){
                res.push_back({i-1,j});
            }
        }
        if(i+1<board.size()) {
            if(mark[i+1][j]==0&&board[i+1][j]=='O'){
                res.push_back({i+1,j});
            }
        }
        return res;
    }
    bool getArea(int i,int j, queue<pair<int,int>> &fillArea,vector<vector<char>>& board,vector<vector<int>> &mark){
        queue<pair<int,int>> q;
        vector<pair<int,int>> neighber;
        pair<int,int> cur;
        q.push({i,j});
        bool flag=true;
        while(!q.empty()){
            cur=q.front();
            q.pop();
            //mark[cur[0]][cur[1]]=1;
            if(onBoard(cur.first,cur.second,board)){
                flag = false;
            }
            if (flag){
                fillArea.push(cur);
            }
            
            neighber=getNeighber(cur.first,cur.second,board,mark);
            
            for(int index=0;index<neighber.size();index++){
                if(mark[neighber[index].first][neighber[index].second]==0
                &&board[neighber[index].first][neighber[index].second]=='O'){
                    q.push(neighber[index]);
                }
                mark[neighber[index].first][neighber[index].second]=1;
            }
        }
        return flag;
    }

    void fill(queue<pair<int,int>> &fillArea, vector<vector<char>>& board){
        while(!fillArea.empty()){
            pair<int,int> cur=fillArea.front();
            fillArea.pop();
            board[cur.first][cur.second]='X';
        }
    }

    void solve(vector<vector<char>>& board) {
        if(board.size()==0){
            return;
        }
        vector<vector<int>> mark;
        mark.resize(board.size(),vector<int>(board[0].size(),0));
        queue<pair<int,int>> fillArea;
        for(int i=0;i<board.size();i++){
            bool ifFill=false;
            for(int j=0;j<board[i].size();j++){
                if(mark[i][j]==0&&board[i][j]=='O'){
                    ifFill=getArea(i,j,fillArea,board,mark);
                }else{
                    mark[i][j]=1;
                }
                if(ifFill){
                    fill(fillArea,board);
                }else{
                    while(!fillArea.empty()){
                        fillArea.pop();
                    }
                }
            }
        }
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size();
        vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int,int>> q;
        if (m==0){
            return ;
        }
        int n= rooms[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int index=0;index<4;index++){
                int x = i + dirs[index].first,  y = j + dirs[index].second;
                if (x < 0 || y < 0 || x >= m || y >= n || rooms[x][y] <= rooms[i][j]+1) 
                    continue;
                rooms[x][y]=rooms[i][j]+1;
                q.emplace(x,y);
            }
        }
    }
};