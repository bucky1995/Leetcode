class Solution {
public:
    class edge{
    public:
        int s;
        int t;
        int time;
    };
    vector<int> arrived;
    unordered_map<int, vector<edge>> g;
    void dfs(int cur, int curTime){
        if(curTime >= arrived[cur]){
            return;
        }
        arrived[cur] = curTime;
        
        for(edge e: g[cur]){
            int next = e.t;
            int time = e.time;
            dfs(next, curTime+time);
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(vector<int> time : times){
            edge e;
            e.s = time[0];
            e.t = time[1];
            e.time = time[2];
            g[time[0]].push_back(e);
        }
        arrived = vector<int>(n+1, INT_MAX);
        dfs(k, 0);
        int res = -1;
        for(int i=1;i<=n;i++){
            res = max(res, arrived[i]);
        }
        return res == INT_MAX ? -1:res;
    }
};