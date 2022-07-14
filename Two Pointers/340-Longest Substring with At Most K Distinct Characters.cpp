class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.size()<=k) return s.size();
        if(k==0)    return 0;
        
        int left = 0;
        int right = 0;
        
        int sz = s.size();
        unordered_map<int,int> hash;
        int len = 0;
        int max_len = 1;
        
        while(left<=right && left<sz && right<sz){
            if(hash.size()<k){
                if(hash.find(s[right]) == hash.end()){
                    hash[s[right]] = 1;
                }else{
                    hash[s[right]]++;
                }
                len++;
                right++;
            }else if(hash.size()==k){
                if(hash.find(s[right]) != hash.end()){
                    len++;
                    hash[s[right]]++;
                    right++;
                }else{
                    hash[s[right]]=1;
                    right++;
                    len++;
                    while(left<sz && hash.size()>k){
                        hash[s[left]]--;
                        if(hash[s[left]] == 0){
                            hash.erase(s[left]);
                        }
                        left++;
                        len--;
                    }
                }
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};