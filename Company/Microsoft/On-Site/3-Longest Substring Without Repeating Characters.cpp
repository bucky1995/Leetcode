class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char,int> hash;
        
        int l = 0;
        int r = 0;
        
        while(r<s.size()){
            char c = s[r];
            hash[c]++;
            
            while(hash[c]>1){
                hash[s[l]]--;
                l++;
            }
            
            res = max(res, r-l+1);
            
            r++;
            
        }
        return res;
    }
};