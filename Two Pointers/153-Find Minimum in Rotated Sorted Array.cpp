class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.front() <= nums.back())  return nums.front();
        int left =0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            
            if(mid >0 && nums[mid-1]>nums[mid]) return nums[mid];
            if(mid<nums.size()-1 && nums[mid]>nums[mid+1])  return nums[mid+1];
            
            if(nums[mid]>=nums.front())     left = mid+1;
            else    right = mid-1;
        }
        return 0;
    }
};