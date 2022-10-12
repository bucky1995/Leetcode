class Solution {
public:
    vector<string> res;
    void dfs(string cur, int left, int right){
        if(right<left){
            return;
        }
        if(left == 0 && right == 0){
            res.push_back(cur);
            return;
        }
        if(left>0)  dfs(cur+"(", left-1, right);
        if(right>0) dfs(cur+")", left, right-1);
    }
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return res;
    }
};