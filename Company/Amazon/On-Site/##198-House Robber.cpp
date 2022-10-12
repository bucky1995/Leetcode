class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 0);
        memo = vector<int>(nums.size(), -1);
        return robhelper(nums, nums.size()-1);
        
    }
    
    int robhelper(vector<int> nums, int i){
        if(i<0)
            return 0;
        if(memo[i]>=0)
            return memo[i];
        
        memo[i] = max(
            robhelper(nums, i-2) + nums[i],
            robhelper(nums, i-1)
        );
        return memo[i];
        
    }
};