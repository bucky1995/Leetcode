#include <iostream> 
#include <unordered_map> 
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool knows(int a, int b);
    int findCelebrity_1(int n) {
        int candidates = 0;
        for(int i=1;i<n;i++){
            if(knows(candidates,i)){
                candidates=i;
            }
        }
        for(int i=0;i<n;i++){
            if(!knows(i,candidates)){
                return -1;
            }
            if(knows(candidates,i)&&i!=candidates){
                return -1;
            }
        }
        return candidates;
    }

    int numDecodings(string s) {
        int n = s.size();
        int n0=1;
        int n1=(s[0]=='0')?0:1;
        for(int i=1;i<n;i++)
        {
            int tmp=n1;
            if(s[i]=='0')
                n1=0;
            if((s[i-1]=='2'&&s[i]<='6')||s[i-1]=='1')
                n1+=n0;
            if(n1==0)
                return 0;
            n0=tmp;
        }
        return n1;
    }

    bool isOneEditDistance(string s, string t) {
        int m=s.size(),n=t.size();
        if(m>n){
            return isOneEditDistance(t,s);
        }
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                if(m==n){
                    return s.substr(i+1)==t.substr(i+1);
                }else{
                    return s.substr(i)==t.substr(i+1);
                }
            }
        }
        return false;
    }
     
    //Greedy Alogrithm
    string intToRoman(int num) {
        vector<string> Ro={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> val={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string result;
        for(int i=0;i<Ro.size();i++){
            while(num>=val[i]){
                result+=Ro[i];
                num-=val[i];
            }
        }
        return result;
    }


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

};