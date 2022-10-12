class Solution {
public:
    vector<vector<int>> memo;
    int numTrees(int n) {
        memo = vector<vector<int>>(n+1, vector<int>(n+1,0));
        return count(1, n);
    }
    int count(int l, int r){
        if(l>r) return 1;
        if(memo[l][r]!=0)   return memo[l][r];
        
        int res = 0;
        for(int i=l;i<=r;i++){
            int left = count(l, i-1);
            int right = count(i+1, r);
            
            res += left* right;
        }
        memo[l][r] = res;
        return res;
    }
};