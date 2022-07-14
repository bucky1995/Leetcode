class Solution {
public:
    vector<vector<int>> res;
    void deep_generate(int start, int n, int k, vector<int> buffer){
        if(buffer.size() == k){
            res.push_back(buffer);
            return;
        }
                
        for(int i=start;i<=n;i++){
            buffer.push_back(i);
            deep_generate(i+1, n, k, buffer);
            buffer.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        deep_generate(1, n, k, vector<int>{});
        return res;
    }
};