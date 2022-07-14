class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0;
        bool all_equal = false;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            res+=nums[i]-nums.front();
        }
        return res;
        
    }
};