class Solution {
public:
    string t1, t2;
    vector<vector<int>> buffer;
    int longestCommonSubsequence(string text1, string text2) {
        buffer = vector<vector<int>>(text1.size()+1, vector<int>(text2.size()+1, -1));
        t1 = text1;
        t2 = text2;
        return helper(0,0);
    }
    int helper(int p1, int p2){
        if(p1 == t1.size() || p2 == t2.size()){
            return 0;
        }

        if(buffer[p1][p2]!=-1){
            return buffer[p1][p2];
        }
        int res = 0;
        if(t1[p1] == t2[p2]){
            res = helper(p1+1, p2+1)+1;
        }else{
            res = max(helper(p1+1, p2), helper(p1, p2+1));
        }
        buffer[p1][p2] = res;
        return res;
    }
};