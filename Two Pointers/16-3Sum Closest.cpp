class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left_boundry = 0;
        if(nums.size()<3)   return -1;
        int diff = INT_MAX;
        
        while(left_boundry<nums.size()-2){
            int left = left_boundry+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[left_boundry]+nums[left]+nums[right];
                if(sum == target)   return sum;
                else{
                    diff = abs(diff) > abs(sum-target) ? target-sum : diff;
                    if(sum>target)  right--;
                    else    left++;
                }
            }
            left_boundry++;
        }
        return target - diff;
    }
};