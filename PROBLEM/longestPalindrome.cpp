#include <iostream> 
#include <unordered_map> 
#include <vector>
#include <string.h>
using namespace std;

class Solution_DP {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1){
            return s;
        }
        int n = s.size();
        vector<vector<int>> map(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            map[i][i] = 1;
        }
        int start = 0;
        int maxlen = 1;
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                map[i][i+1] = 1;
                start = i;
                maxlen = 2;
            }
        }
        for(int k = 3;k<=n;k++){
            for(int i=0; i<n-k+1;i++){
                int j = i+k-1;
                if(s[i] == s[j]){
                    if(map[i+1][j-1] == 1){
                        map[i][j] = 1;
                        if(k > maxlen){
                            maxlen = k;
                            start = i;
                        }
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};

class Solution_Enumeration {
public:
    string longestPalindrome(string s) {
        if(s.size()<2){
            return s;
        }
        int n = s.size();
        int start = 0;
        int maxlen = 0;
        for(int i=0;i<=n-1;i++){
            int len;
            len = expend(s,i,i);
            if(len>maxlen){
                maxlen = len;
                start = i-len/2;
            }
            len = expend(s,i,i+1);
            if(len>maxlen){
                maxlen = len;
                start = i - len/2 +1;
            }
        }
        return s.substr(start,maxlen);
    }
    int expend(string s, int left, int right){
        int len = 0;
        while(left>=0 && right < s.size()){
            if(s[left]!=s[right]){
                break;
            }
            len += (left == right? 1 : 2);
            left--;
            right++;
        }
        return len;
    }
};