class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)    return 0;
        
        int left = 0;
        int right = nums.size()-1;
        if(nums[left]>nums[left+1])     return left;
        if(nums[right]>nums[right-1])   return right;
        left++;
        right--;
        while(left<=right){
            int mid = left+(right-left)/2;
            
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])  return mid;
            if(nums[mid]<nums[mid-1]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return -1;
    }
};