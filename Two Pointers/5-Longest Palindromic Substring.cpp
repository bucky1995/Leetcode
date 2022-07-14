class Solution {
public:
    
    int extend(string s, int left, int right){
        int res = 0;
        while(left>=0 && right<s.size()){
            if(s[left] == s[right]){
                res++;
            }else{
                break;
            }
            left--;
            right++;
        }
        return res*2;
    }
    int extend_even(string s, int start){
        int left = start;
        int right = start+1;
        return extend(s, left, right);
       
    }
    
    int extend_odd(string s, int start){
        int left = start-1;
        int right = start+1;
        return extend(s, left, right)+1;
    }
    string longestPalindrome(string s) {
        int max_left = 0;
        int max_len = 1;
        
        for(int i=0;i<s.size();i++){
            int len = extend_even(s,i);
            if(len>max_len){
                max_len = len;
                max_left = i-len/2+1;
            }
            len = extend_odd(s,i);
            if(len>max_len){
                max_len = len;
                max_left = i-len/2;
            }
        }

        return s.substr(max_left, max_len);
    }
};