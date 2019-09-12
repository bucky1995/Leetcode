#include <iostream> 
#include <unordered_map> 
#include <vector>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
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
    
    void deepCombine(string num, int target, int curPos, long curV, long lastV, 
                     string temp, vector<string> &res){
        if(curPos == num.length()&&target==curV){
            res.push_back(temp);
            return;
        }
        for(int i=1;i<=num.size()-curPos;i++){
            string newVstr=num.substr(curPos,i);
            if(i>1&&newVstr[0]=='0') continue;
            long newV=stol(newVstr);
            if(curPos==0){
                deepCombine(num,target,i,newV,newV,newVstr,res);
                continue;
            }
            deepCombine(num,target,curPos+i,curV-lastV+lastV*newV,lastV*newV,
                       temp+"*"+newVstr,res);//when new op is *

            deepCombine(num,target,curPos+i,curV+newV,newV,
                       temp+"+"+newVstr,res);//when new op is +

            deepCombine(num,target,curPos+i,curV-newV,-newV,
                       temp+"-"+newVstr,res);//when new op is -
            
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        deepCombine(num,target,0,0,0,
                   "",res);
        return res;
    }
    //再做递归的时候传递大变量，在这题中就是hashmap，会大幅降低算法效率，全局变量很重要
    unordered_map<string,vector<string>> hash;
    void set(vector<string> word){
        for(int i=0;i<word.size();i++){
            string pre;
            for(int j=0;j<word[i].size();j++){
                pre.push_back(word[i][j]);
                hash[pre].push_back(word[i]);
            }
        }
    }

    bool checkPre(vector<string> cur,string next,string &pre){
        cur.push_back(next);
        int pos = cur.size();
        if(pos==next.size()){
            return true;
        }
        vector<string> res;
        string temp;
        pre="";
        for(int j=pos;j<next.size();j++) {
            for (int i = 0; i < cur.size(); i++) {
                temp+=cur[i][j];
            }
            if(j==pos){
                pre=temp;
            }
            if(hash.find(temp)==hash.end())   return false;
            temp="";
        }
        return true;
    }

    void deepSquares(vector<string> waitList, int maxL, vector<string> cur,vector<vector<string>> &res){
        if(cur.size()==maxL){
            res.push_back(cur);
            return;
        }
        while(!waitList.empty()){
            string pre;
            bool flag = checkPre(cur,waitList.back(),pre);
            if(flag){
                cur.push_back(waitList.back());
                waitList.pop_back();
                deepSquares(hash[pre],maxL,cur,res);
                cur.pop_back();
            }else{
                waitList.pop_back();
            }
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        queue<string> a;
        set(words);
        hash[""]={""};
        deepSquares(words,words[0].size(),vector<string>(),res);
        return res;
    }

    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }

        unordered_map<char,int> hash;
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        int count=hash.size();
        int start=0,tail=0;
        int minlen=INT_MAX;
        string res="";
        int resStart=0;
        for(;tail<s.size();tail++){
            if(hash.find(s[tail])!=hash.end()){
                hash[s[tail]]--;
                if(hash[s[tail]]==0){
                    count--;
                }
            }
            if(count==0){

                do{
                    if(hash.find(s[start])!=hash.end()){
                        hash[s[start]]++;
                        if(hash[s[start]]>0)
                            count++;
                    }
                    start++;
                }while(count==0);
                start--;
                if(minlen>tail-start+1){
                    resStart=start;
                    minlen=tail-start+1;
                }
                start++;
            }
        }
        if(minlen==INT_MAX){
            return "";
        }else{
            return s.substr(resStart,minlen);
        }
    }

    //Divide and concue, so damn clever
    ListNode* mergeTwo(ListNode* a,ListNode* b){
        ListNode* res;
        if(a==NULL){
            return b;
        }else if(b==NULL){
            return a;
        }
        if(a->val<=b->val){
            res=a;
            res->next=mergeTwo(a->next,b);
        }else{
            res=b;
            res->next=mergeTwo(a,b->next);
        }
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        int k=lists.size()-1;
        while(k!=0){
            int i=0,j=k;
            while(i<j){
                lists[i]=mergeTwo(lists[i],lists[j]);
                i++;j--;
            }
            k=j;
        }
        return lists[0]; 
    }
};