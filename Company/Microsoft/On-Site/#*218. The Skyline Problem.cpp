class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        unordered_set<int> edgeSet;
        for(vector<int> building : buildings){
            edgeSet.insert(building[0]);
            edgeSet.insert(building[1]);
        }
        
        vector<int> edges(edgeSet.begin(), edgeSet.end());
        sort(edges.begin(),edges.end());
        
        unordered_map<int, int> edgeIndexMap;
        
        for(int i=0;i<edges.size();i++){
            edgeIndexMap[edges[i]] = i;
        }        
        
        vector<int> heights(edges.size());
        
        for(vector<int> building : buildings){
            int left = building[0];
            int right = building[1];
            int height = building[2];
            
            int leftIndex = edgeIndexMap[left];
            int rightIndex = edgeIndexMap[right];
            
            for(int i= leftIndex;i<rightIndex;i++){
                heights[i] = max(heights[i], height);
            }
        }
        
        vector<vector<int>> res;
        
        for(int i=0;i<heights.size();i++){
            int curHeight = heights[i];
            int curPos = edges[i];
            
            if(i == 0 || curHeight != heights[i-1]) {
                res.push_back({curPos, curHeight});
            }
        }
        
        return res;
        
    }
};