class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_sum = nums.front();
        int sum = max_sum;
        
        for(int i=1;i<nums.size();i++){
            int num = nums[i];
            sum = max(sum+num , num);
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};