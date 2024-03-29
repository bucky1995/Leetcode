class Solution {
public:
    /**
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(vector<int> &nums, int target) {
        // write your code here
        if(nums.size()<2)   return 0;
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size()-1;

        int diff = INT_MAX;
        while(left < right){
            int sum = nums[left]+nums[right];
            if(sum == target)    return 0;
            else {
                diff = min(diff,abs(target - nums[left] - nums[right]));
                if(sum>target){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return diff;
    }
};