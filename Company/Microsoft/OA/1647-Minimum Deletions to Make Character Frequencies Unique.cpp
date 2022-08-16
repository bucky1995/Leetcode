class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> alpha_count;
        vector<char> alpha;
        for(char c: s){
            if(!alpha_count.count(c))
                alpha.push_back(c);
            alpha_count[c]++;
        }
        int res = 0;
        unordered_set<int> used;
        for(int i=0;i<alpha.size();i++){
            char c =alpha[i];
            while(alpha_count[c]>0 && used.count(alpha_count[c])){
                alpha_count[c]--;
                res++;
            }
            if(alpha_count[c]!=0)
                used.insert(alpha_count[c]);
        }
        return res;
    }
};