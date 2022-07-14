class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = 1;
        while(right<nums.size() && nums[right]<=target){
            right++;
        }
        if(right>1) right--;
        while(left<right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                break;
            }else{
                if(sum>target){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return vector<int>({left+1, right+1});
    }
};