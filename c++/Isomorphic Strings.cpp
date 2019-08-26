#include <iostream> 
#include <unordered_map> 
#include<vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if( s.length()!=t.length()){
            return false;
        }
        int length=t.length();
        
        unordered_map<char,char> hashstot;
        unordered_map<char,char> hashttos;
        for(int i=0;i<length;i++){
            if(hashstot.find(s[i])!=hashstot.end()){
                {   
                    if(hashstot[s[i]]!=t[i]){
                        return false;
                    }
                }
            }
            else if(hashttos.find(t[i])!=hashttos.end()){
                    if(hashttos[t[i]]!=s[i]){
                        return false;
                    }
            }else{
                hashstot[s[i]]=t[i];
                hashttos[t[i]]=s[i];
            }
        }
        return true;
    }
};