class Solution {
public:
    int max_len;
    string res;
    void singelStart(string s, int index){
        int l = index-1;
        int r = index+1;
        int len = 1;
        while(l>=0 && r<s.size() && s[l] == s[r]){
            len+=2;
            l--;
            r++;
        }
        l++;
        if(max_len<len){
            max_len = len;
            res = s.substr(l,len);
        }
    }
    
    void dualStart(string s, int index){
        int l = index;
        int r = index+1;
        int len = 0;
        while(l>=0 && r<s.size() && s[l] == s[r]){
            len+=2;
            l--;
            r++;
        }
        l++;
        if(max_len<len){
            max_len = len;
            res = s.substr(l,len);
        }
    }
    string longestPalindrome(string s) {
        max_len = 1;
        res = s.front();
        for(int i=0;i<s.size();i++){
            singelStart(s, i);
            dualStart(s, i);
        }
        
        return res;
    }
};