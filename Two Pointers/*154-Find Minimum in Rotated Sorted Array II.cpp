class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1 || nums.front() < nums.back())    return nums.front();
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left<=right){
            int mid = left+(right-left)/2;
            
            if(mid>0 && nums[mid]<nums[mid-1])  return nums[mid];
            if(mid<nums.size()-1 && nums[mid]>nums[mid+1])  return nums[mid+1];
            //if(nums[mid] == nums[left] && nums[mid] == nums[right]) return nums[mid];
            
            if(nums[mid] < nums[left] || nums[mid]<nums[right])  right = mid;
            else if(nums[mid] > nums[left] || nums[mid] >nums[right]) left = mid;
            else if(nums[mid] == nums[left] || nums[mid] == nums[right])    right--;
        }
        
        return nums[left];  //when all elements are the same
    }
};