#include <iostream> 
#include <unordered_map> 
#include <unordered_set> 
#include<vector>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0){
            return false;
        }
        vector<char> stack;
        unordered_map<char,char> rule;
        rule['(']=')';
        rule['[']=']';
        rule['{']='}';
        unordered_set<char> left;
        left.insert('(');
        left.insert('[');
        left.insert('{');
        for(int i=0;i<s.size();i++){
            if(left.find(s[i])!=left.end()){
                stack.push_back(s[i]);
            }else{
                if(stack.empty()){
                    return false;
                }
                char temp=stack.back();
                stack.pop_back();            
                if(s[i]!=rule[temp]){
                    return false;
                }
            }
        }
        if(!stack.empty()){
            return false;
        }else{
            return true;
        }   
    }
};