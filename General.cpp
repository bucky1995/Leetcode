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
};