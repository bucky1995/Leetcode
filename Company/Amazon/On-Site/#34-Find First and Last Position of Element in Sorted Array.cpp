class Solution {
public:
    int findLeft(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();
        while(left < right){
            int mid = left + (right-left)/2;
            int num = nums[mid];
            if(num == target){
                right = mid;
            }else if(num < target){
                left = mid+1;
            }else if(num > target){
                right = mid;
            }
        }
        if(left == nums.size()){
            return -1;
        }
        return nums[left] == target ? left : -1;
    }
    
    int findRight(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();
        
        while(left<right){
            int mid = left+(right-left)/2;
            int num = nums[mid];
            if(num == target){
                left = mid+1;
            }else if(num<target){
                left = mid+1;
            }else if(num>target){
                right = mid;
            }
        }
        
        if(left == 0)
            return -1;
        return nums[left-1] == target ? left-1 : -1;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeft(nums, target);
        int right = findRight(nums, target);
        return {left, right};
    }
};