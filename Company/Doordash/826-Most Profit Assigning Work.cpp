class Solution {
public:
    static bool compare(pair<int,int> a, pair<int,int> b){
        return a.first > b.first;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> buffer;
        for(int i=0;i<difficulty.size();i++){
            buffer.push_back({profit[i], difficulty[i]});
        }

        sort(buffer.begin(), buffer.end(), compare);
        int res = 0;
        for(int c : worker){
            for(int i=0;i<buffer.size();i++){
                if(c>=buffer[i].second){
                    res+=buffer[i].first;
                    break;
                }
            }
        }
        return res;
    }
};