class Solution {
public:
    vector<string> res;
    string buffer;
    void dfs(int left, int right){
        if(right < left)    return;
        if(right<0||left<0) return;
        if(right == 0&&left==0){
            res.push_back(buffer);
            return;
        } 
        buffer.push_back('(');
        dfs(left-1,right);
        buffer.pop_back();
        
        buffer.push_back(')');
        dfs(left,right-1);
        buffer.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        buffer = "";
        dfs(n,n);
        return res;
    }
};