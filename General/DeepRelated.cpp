#include <iostream> 
#include <unordered_map> 
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
   vector<string> letterCombinations_general(string digits) {
        unordered_map <char,vector<string>> k;
        vector<string> res;
        if(digits.size()==0) return res;
        k['2'] = {"a","b","c"};
        k['3'] = {"d","e","f"};
        k['4'] = {"g","h","i"};
        k['5'] = {"j","k","l"};
        k['6'] = {"m","n","o"};
        k['7'] = {"p","q","r","s"};
        k['8'] = {"t","u","v"};
        k['9'] = {"w","x","y","z"};
        for(int i=0;i<k[digits[0]].size();i++){
            res.push_back(k[digits[0]][i]);
        }
        for(int i=1;i<digits.size();i++){
            vector<string> temp = res;
            int count=k[digits[i]].size();
            int curcount=res.size();
            int copycount=count-1;
            for(int j=0;j<copycount;j++){
                res.insert(res.end(),temp.begin(),temp.end());
            }
            for(int j=0;j<count;j++){
                for(int f=j*curcount;f<(j+1)*curcount;f++){
                    res[f]+=k[digits[i]][j];
                }
            }
        }
        return res;             
    }

    void diveNum(int cur,int len,unordered_map <char,vector<string>> k,
                vector<string> &res,string buffer,string digits){
        if(cur==len){
            res.push_back(buffer);
            return;
        }
        for(int i=0;i<k[digits[cur]].size();i++){
            diveNum(cur+1,len,k,res,buffer+k[digits[cur]][i],digits);
        }
    }
    vector<string> letterCombinations_dfs(string digits) {
        unordered_map <char,vector<string>> k;
        vector<string> res;
        if(digits.size()==0) return res;
        k['2'] = {"a","b","c"};
        k['3'] = {"d","e","f"};
        k['4'] = {"g","h","i"};
        k['5'] = {"j","k","l"};
        k['6'] = {"m","n","o"};
        k['7'] = {"p","q","r","s"};
        k['8'] = {"t","u","v"};
        k['9'] = {"w","x","y","z"};
        diveNum(0,digits.size(),k,res,"",digits);
        return res;
        
    }

    void deepBreak(int lastF,int remain,vector<vector<int>> &res,vector<int> &temp){
        if(!temp.empty()){
            temp.push_back(remain);
            res.push_back(temp);
            temp.pop_back();
        }
        for(int i=lastF;i<remain;i++){
            if(remain/i<i)
                break;
            if(remain%i==0){
                temp.push_back(i);
                deepBreak(i,remain/i,res,temp);       
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
         vector<int> temp;
        deepBreak(2,n,res,temp);
        return res;
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
};