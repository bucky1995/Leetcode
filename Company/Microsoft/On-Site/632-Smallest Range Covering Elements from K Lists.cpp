class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int min_dis = INT_MAX;
        int l,r;
        vector<int> next = vector<int>(nums.size(), 0);
        int min_i= 0;
        
        bool stop = false;
        
        while(!stop){
            int high = INT_MIN;
            int low = INT_MAX;
            for(int i=0;i<nums.size();i++){
                int num = nums[i][next[i]];
                if(low >= num){
                    low = num;
                    min_i = i;
                }
                high = max(high, num);
            }
            int dis = high-low;
            if(dis<min_dis){
                l = low;
                r = high;
                min_dis = dis;
            }
            
            next[min_i]++;
            if(next[min_i] >= nums[min_i].size()){
                stop = true;
            }
        }
        return vector<int>{l,r};
    }
};