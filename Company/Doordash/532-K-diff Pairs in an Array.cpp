class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int res = 0;

        for(int num : nums){
            map[num]++;            
        }
        
        for(pair<int, int> node : map){
            int val = node.first;
            int count = node.second;

            if(k == 0 && map[val]>1){
                res++;
            }else if(k>0 && map.count(val+k)!=0){
                res++;
            }
        }
        return res;
    }
};