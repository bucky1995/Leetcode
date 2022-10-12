class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        return a.front()<b.front();
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int min = 0;
        
        int i=0;
        unordered_set<int> hash;
        while(hash.size()!=intervals.size()){
            min++;
            int cur_end = 0;
            for(int i=0;i<intervals.size();i++){
                int start = intervals[i].front();
                int end = intervals[i].back();
                if(cur_end<=start && hash.count(i)==0){
                    hash.insert(i);
                    cur_end = end;
                }
            }
        }
        return min;
    }
};