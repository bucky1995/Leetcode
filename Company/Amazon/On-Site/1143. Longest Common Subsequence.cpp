class Solution {
public:
    vector<vector<int>> memo;
    string t1, t2;
    int longestCommonSubsequence(string text1, string text2) {
        memo = vector<vector<int>>(text1.size()+1, vector<int>(text2.size()+1, -1));
        t1 = text1;
        t2 = text2;
        return memoSolve(0,0);
        
    }
    
    int memoSolve(int p1, int p2){
        if(p1 == t1.size() || p2 == t2.size())
            return 0;
        if(memo[p1][p2]!=-1){
            return memo[p1][p2];
        }
        int res = 0;
        
        if(t1[p1] == t2[p2]){
            res = memoSolve(p1+1, p2+1) +1;
        }else{
            res = max(memoSolve(p1, p2+1), memoSolve(p1+1, p2));
        }
        
        memo[p1][p2] = res;
        return res;
    }
};