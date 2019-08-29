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
    
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[2]<=rec2[0]||rec1[0]>=rec2[2]||rec1[1]>=rec2[3]||rec1[3]<=rec2[1]){
            return false;
        }else{
            return true;
        }
    }

    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0'){
                    return false;
                }
                int Deviation = 0;
                while (j < abbr.size() && isdigit(abbr[j])) {
                    Deviation = Deviation * 10 + abbr[j] - '0';
                    j++;
                }
                i=i+Deviation;
            }else if (word[i] != abbr[j]) {
                return false;
            }else{
                i++;j++;
            }
        }
        return i == word.size() && j == abbr.size();
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
};