class Solution {
public:
    //{i,j,a,b}
    class comp {
        public:
        bool operator() (vector<int> a, vector<int> b){
            return a[2]+a[3] > b[2]+b[3];
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        
        set<vector<int>> visited;
        vector<vector<int>> res;
        pq.push({0,0,nums1.front(), nums2.front()});
        visited.insert({0,0});
        
        while(k>0 && !pq.empty()){
            vector<int> top = pq.top();
            pq.pop();
            res.push_back({top[2], top[3]});
            
            int topi = top[0];
            int topj = top[1];
            
            if(topi+1<nums1.size() && visited.count({topi+1, topj})==0){
                visited.insert({topi+1, topj});
                pq.push({topi+1, topj, nums1[topi+1], nums2[topj]});
            }
            
            if(topj+1<nums2.size() && visited.count({topi, topj+1})==0){
                visited.insert({topi, topj+1});
                pq.push({topi, topj+1, nums1[topi], nums2[topj+1]});
            }
            
            k--;
        }
        return res;
        
    }
};