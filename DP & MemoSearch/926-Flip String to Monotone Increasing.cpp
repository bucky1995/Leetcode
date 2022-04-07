class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> P(s.size()+1,0);
        for(int i=1;i<=s.size();i++){
            P[i] = P[i-1]+(s[i-1]=='1'?1:0);
        }
        int res = INT_MAX;
        for(int i=0;i<=s.size();i++){
            int flip_count = P[i]+(s.size()-i-(P[s.size()]-P[i]));
            res = res > flip_count? flip_count:res;
        }
        return res;
    }
};