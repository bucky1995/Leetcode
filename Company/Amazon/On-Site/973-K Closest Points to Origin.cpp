class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //sort(points.begin(),points.end(), compare);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        for(int i=0;i<points.size();i++){
            minheap.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        }
        
        vector<vector<int>> res;
        
        while(K!=0){
            vector<int> pair = minheap.top();
            int i = pair[1];
            minheap.pop();
            res.push_back(points[i]);
            K--;
            
        }
        return res;
        
        
        //return {points.begin(), points.begin() +K};
    }
};