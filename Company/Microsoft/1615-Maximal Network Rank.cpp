class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> graph;
        for(int i=0;i<roads.size();i++){
            int city1 = roads[i][0];
            int city2 = roads[i][1];
            graph[city1].insert(city2);
            graph[city2].insert(city1);
        }
        
        int max_rank = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int duplicate = graph[i].count(
                    j
                )?1:0;
                
                int rank = graph[i].size() + graph[j].size()-duplicate;
                max_rank = max(rank, max_rank);
            }
        }
        return max_rank;
        
    }
};